/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:08:52 by wricky-t          #+#    #+#             */
/*   Updated: 2024/01/05 21:02:06 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

typedef std::list<GroupIterator<IntVectIte> > MainChain;
typedef MainChain::iterator MainChainIte;
typedef std::vector<MainChainIte> Pend;

/**
 * @brief Sort and swap pairs. Each pair consist of two element/group. The ideal order of the pair is [small, large].
 */
static void sortAndSwapPairs(GroupIterator<IntVectIte> begin, GroupIterator<IntVectIte> end)
{
    for (GroupIterator<IntVectIte> it = begin; it != end; it += 2)
    {
        if (*(it + 1) < *it)
            swapRange(it, it + 1);
    }
}

/**
 * @brief Set up main chain and pend
 *
 * Definition:
 * -- Main Chain --
 * The main chain is a list that stores all our sorted elements or groups.
 *
 * -- Pend --
 * The pend is used to record the ideal insertion locations for the remaining elements.
 * These ideal locations are used as starting points for binary insertion, avoiding unnecessary search.
 *
 *
 * Key Points / Facts:
 * 1. After sorting the pairs, the first pair comprises:
 *      a. The smallest larger number among all the pairs (begin + 1).
 *      b. The smaller number in the pair is guaranteed to be smaller than all the larger numbers in all pairs (begin).
 *    Therefore, it's safe to initialize the main chain with these two numbers first.
 *
 * 2. For all the smaller numbers in each pair (excluding the first one, which is already in the main chain),
 *    they will be inserted before their corresponding larger number pair. We record these 'ideal locations' in pend.
 *    Pend stores iterators indicating where the smaller elements should be inserted during binary insertion.
 */
static void setupChainAndPend(GroupIterator<IntVectIte> begin, size_t size, MainChain &mainChain, Pend &pend)
{
    mainChain.push_back(begin);
    mainChain.push_back(begin + 1);

    size_t index = (4 - 1);
    for (; index < size; index += 2)
    {
        MainChainIte loc = mainChain.insert(std::end(mainChain), (begin + index));
        pend.push_back(loc);
    }
}

/**
 * @brief Custom comparator function for lower_bound
 */
static bool comparator(const GroupIterator<IntVectIte> &lhs, const int &rhs)
{
    return *lhs < rhs;
}

/**
 * @brief Insert pending elements from 'pend' into 'mainChain' at ideal insertion locations.
 *
 * This function iterates through the 'pend' container in parallel with the smaller values of each pair.
 * For each pending element, it performs a binary search within 'mainChain' to find the ideal insertion
 * location and then inserts the element at that position.
 *
 * If there's a leftover element ('leftOver') during this recursive call, it is also inserted into 'mainChain.'
 * For the leftover element, since we don't know the ideal location, we perform a binary search within 'mainChain.'
 */
static void insertPendToMainChain(MainChain &mainChain, Pend &pend, GroupIterator<IntVectIte> &begin, bool hasLeftover, GroupIterator<IntVectIte> &leftOver)
{
    Pend::iterator currentPend = pend.begin();
    GroupIterator<IntVectIte> pendValue = begin + 2; // the 2nd smaller value in all pairs

    for (; currentPend != pend.end(); currentPend += 1)
    {
        // Find insertion position using binary search
        MainChainIte insertPos = std::lower_bound(mainChain.begin(), *currentPend, *pendValue, comparator);
        mainChain.insert(insertPos, pendValue);
        pendValue += 2;
    }

    if (hasLeftover)
    {
        MainChainIte insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), *leftOver, comparator);
        mainChain.insert(insertPos, leftOver);
    }
}

/**
 * @brief Synchronize changes from the main chain back to the original data structure.
 *
 * This function is responsible for copying the sorted elements from the main chain
 * back to the original data structure indicated by 'begin'. It utilizes a temporary
 * cache to efficiently store the sorted elements before moving them back.
 */
static void syncChanges(MainChain &mainChain, GroupIterator<IntVectIte> &begin)
{
    IntVect cache;

    for (MainChainIte it = mainChain.begin(); it != mainChain.end(); ++it)
    {
        // Get the group iterator from the main chain
        GroupIterator<IntVectIte> groupIter = *it;

        // Extract the begin and end iterators for the group
        IntVectIte begin = groupIter.base();
        IntVectIte end = begin + groupIter.size();

        // Move the elements from the group to the cache
        std::move(begin, end, std::back_inserter(cache));
    }
    // Move the sorted elements from the cache back to the original data structure
    std::move(std::begin(cache), std::end(cache), begin.base());
}

/**
 * @brief Ford-Johnson Algorithm (Merge-Insertion sort)
 *
 * Ford-Johnson algorithm is a recursive sorting algorithm.
 * Base case: When the number of elements/groups is less than 2.
 *
 * The flow of Ford-Johnson algorithm:
 * 1. Check if there is a leftover element. This occurs if the number of elements/groups is odd.
 *      a. If there's a leftover, initialize an iterator to point to it, ensuring it's not passed during iteration.
 * 2. Pair the elements/groups into n/2 pairs and sort them pairwise. The order should be [Small, Large].
 * 3. Populate main chain & pend:
 *      a. Main chain stores the sorted list.
 *      b. Pend stores iterators indicating where smaller elements should be inserted during binary insertion.
 * 4. Insert elements in pend to the main chain using binary insertion.
 * 5. Synchronize the main chain with the original data structure (e.g., vector, list, deque).
 *
 * In each recursive call, the size of each group doubles, and all steps are executed recursively.
 *
 * <>: leftover, ||: group/element
 *
 *                               16 , 91 , 61 , 30 , 8 , 44 , 72 , 17 , 19 , 34
 * 0-     Initial pairing:      |16|,|91|,|61|,|30|,|8|,|44|,|72|,|17|,|19|,|34|
 *          Sort pairwise:      |16|,|91|,|30|,|61|,|8|,|44|,|17|,|72|,|19|,|34| (when we sort, we look at the last number of that group, ensure that it's |small|, |large|, |small|, |large|, ...)
 * 1-Continuation ranking:      |16 , 91|,|30 , 61|,|8 , 44|,|17 , 72|,<19 , 34> (pair them again, but this time group size is 2 * 2)
 *          Sort pairwise:      |30 , 61|,|16 , 91|,|8 , 44|,|17 , 72|
 * 2-Continuation ranking:      |30 , 61 , 16 , 91|,|8 , 44 , 17 , 72|
 *    Sort pairwise again:      |8 , 44 , 17 , 72|,|30 , 61 , 16 , 91|
 * 3-Continuation ranking:      |8 , 44 , 17 , 72 , 30 , 61 , 16 , 91| (opps, number of element is < 2. Stop recursion. PS:|| should consider as one element.)
 *
 * 2-          Main chain:      72 , 91
 *                   Pend:      (empty)
 * 1-          Main chain:      44 , 72 , 91
 *                   Pend:      61 , <34> (leftover)
 *              Insertion:      34 , 44 , 61 , 72 , 91
 * 0-          Main chain:      19 , 34 , 44 , 61 , 72 , 91
 *                   Pend:      8  , 30 , 17 , 16
 *              Insertion:      8 , 16 , 17 , 19 , 30 , 34 , 44 , 61 , 72 , 91 (SORTED)
 */
static void fordJohnsonSort(GroupIterator<IntVectIte> begin, GroupIterator<IntVectIte> end)
{
    size_t size = begin.distance(end);

    // base case
    if (size < 2)
        return;

    // checks for leftover element
    bool hasLeftover = size % 2 != 0;
    GroupIterator<IntVectIte> endIte = hasLeftover ? --end : end;

    // pair elements into n/2 pairs and sort them pairwise
    sortAndSwapPairs(begin, endIte);

    // recursively create pairs and sort
    fordJohnsonSort(GroupIterator<IntVectIte>(begin, begin.size() * 2), GroupIterator<IntVectIte>(end, end.size() * 2));

    // populate main chain and pend
    MainChain mainChain;
    Pend pend;
    setupChainAndPend(begin, (hasLeftover ? size - 1 : size), mainChain, pend);

    // binary insertion
    insertPendToMainChain(mainChain, pend, begin, hasLeftover, endIte);

    // synchronize main chain to the original data structure
    syncChanges(mainChain, begin);
}

void vectorRunner(const IntVect &original, double parsingTime)
{
    IntVect elements;
    double startTime = getTimeStamp();
    double endTime;
    double elapsedTime;

    std::copy(original.begin(), original.end(), std::inserter(elements, elements.end()));
    std::cout << BYELLOW << "Before (VECTOR):" << RESET << std::endl;
    showElements<IntVect>(elements);

    fordJohnsonSort(GroupIterator<IntVectIte>(elements.begin(), 1), GroupIterator<IntVectIte>(elements.end(), 1));

    endTime = getTimeStamp();
    elapsedTime = (endTime - startTime) + parsingTime;

    std::cout << BYELLOW << "After (VECTOR):" << RESET << std::endl;
    showElements<IntVect>(elements);
    showTimeStamp(elements.size(), elapsedTime, VECTOR);
}
