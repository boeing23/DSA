class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:

        # basically you create a adjacency list of every work in wordlist, with adding a * to each char in it

        # for example if you take hit

        # now for hit there can be 3 combos

        # *ot - [hot, dot, lot]
        # h*t - [hot]
        # ho* - [hot]

        # then dot

        
        # d*t - [dot]
        # do* - [dot, dog]

        # dog

        # *og -[dog, log, cog]
        # d*g -[dog]

        # lot
        
        # l*t- [lot]
        # lo*- [lot, log]

        # log

        # l*g - [log]

        # cog

        # c*g - [cog]
        # co* - [cog]


        # now you first add hit,1
        # then you put * on each pos and check if it is present in the map

        # *it not there
        # then h*t it is there now you check hit==hot no it isn't now
        # you push hot,2 in q

        # *ot is this there yes it is, you go to hot but it is already in visited so skip now next 
        # which is dot push in q now q has (dot,2)


        # next you check ho*
        # it is there but hot is in visited so skip


        # next you go in dot and so on

        if len(beginWord)!=len(endWord):
            return 0

        pattern_map=defaultdict(list)

        L=len(beginWord)

        for w in wordList:
            for i in range(L):
                pattern= w[:i] + '*' + w[i+1:]

                pattern_map[pattern].append(w)

        q=deque()
        visited=set()

        q.append([beginWord,1])
        visited.add(beginWord)

        while q:

            currWord, steps= q.popleft()

            for i in range(L):
                pattern=currWord[:i]+'*'+currWord[i+1:]
                for nei in pattern_map[pattern]:
                    if nei==endWord:
                        return steps+1
                    if nei not in visited:
                        q.append([nei,steps+1])
                    visited.add(currWord)
        return 0








        
        