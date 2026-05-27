class Twitter:

    def __init__(self):
        self.counter=0
        self.postlist={}
        self.following_list={}
        
        

    def postTweet(self, userId: int, tweetId: int) -> None:
        # userId -> tweetID
        
        if userId not in self.postlist:
            self.postlist[userId]=[]
        self.postlist[userId].append((self.counter, tweetId))
        self.counter+=1

        

    def getNewsFeed(self, userId: int) -> List[int]:
        # this should basically show the posts of most recent who the user is followig
        # most recent 
        #now this should first get the userlist which the user is following
        userFollowsto = self.following_list.get(userId, set())

        # this gives a list of who the user follows and now our task is to get into that list
        # and see there posts and append to a list now we remove the top when heapsize goes
        #above 10 basically we remove the older posts
        minHeap=[]
        userspost=self.postlist.get(userId,[])
        for posts in userspost:
            heapq.heappush(minHeap,posts)

            while len(minHeap)>10:
                heapq.heappop(minHeap)


        #now i have to find who the user follows to
        #now go to each user id and find there posts
        for user in userFollowsto:
            if user == userId:
                continue
            tweetslist=self.postlist.get(user,[])
            for posts in tweetslist:
                heapq.heappush(minHeap,posts)

                while len(minHeap)>10:
                    heapq.heappop(minHeap)
        

        #now the minHeap has the list of top 10 posts
        sorted_list=sorted(minHeap, reverse=True)
        ans=[]
        for counter,tweetId in sorted_list:
            ans.append(tweetId)
        return ans




    def follow(self, followerId: int, followeeId: int) -> None:

        # flooweeID -> what ids follow him
        # folowerList{
        #     user_id -> set(followers)
        # }
        # if followeeId not in self.follower_list:
        #     self.follower_list[followeeId]=set()
        
        if followerId not in self.following_list:
            self.following_list[followerId] = set()
        self.following_list[followerId].add(followeeId)

        # this will look like
        # {
        #     Yashodhan -> 1,2,4,5  
        # }


        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        #now when you say unfollow get the 
        # if followeeId not in self.follower_list:
        #     return None
        #self.follower_list[followeeId].discard(followerId)
        
        if followerId not in self.following_list:
            return

        self.following_list[followerId].discard(followeeId)
        
