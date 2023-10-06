#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/design-twitter/
*/

/*
I have just maintained a map of users and their tweets along with their time and also I had a map of users and their followers in the form of a set
so when ever a users feed is called I will keep all the tweets of the user and his followers in a priority and queue and loop through other
users whom he/she follows add them into the queue and now take the top 10 of them or until the queue is empty
during following or unfollowing before removing or adding just check if present or not if not present then addition and removal will lead to tle
as it is not map<int, int> mp for every element to intialise to zero by default here every element in the map does not have a by default set

I guess there is no need of any ordering of pairs in the set of usersfeedmap as anyway we are adding the feed into a priority queue, but anyway its a
good exercies of knowing how to write comp functions 
*/
typedef pair<int, int> pi ;
// struct comp{
//     bool operator()(const pi &a, const pi &b)const{
//         return a.first > b.first ;
//     }
// };
class Twitter {
public:
    int timer ;
    map<int, set<pi>> usersfeedmap ;
    map<int, set<int>> followersmap ;
    Twitter() {
        timer = 0 ;  
    }
    
    void postTweet(int userId, int tweetId) {
        usersfeedmap[userId].insert({timer, tweetId}) ;
        timer++ ;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans ;
        priority_queue<pair<int, int>> pq ;
        set<pi> st = usersfeedmap[userId] ;
        for(auto it = st.begin() ; it != st.end() ; it++){
            pq.push(*it) ;
        }
        set<int> st2 = followersmap[userId] ;
        for(auto it = st2.begin() ; it != st2.end() ; it++){
            set<pi> st1 = usersfeedmap[*it] ;
            for(auto it1 = st1.begin() ; it1 != st1.end() ; it1++){
                pq.push(*it1) ; 
            }
        }
        int count = 0 ;
        while(!pq.empty()){
            if(count == 10){
                break ;
            }
            ans.push_back(pq.top().second) ;
            pq.pop() ;
            count++ ;
        }
        return ans ;
    }
    
    void follow(int followerId, int followeeId) {
        if(followersmap.find(followerId) != followersmap.end()){
            followersmap[followerId].insert(followeeId) ;
        }
        else{
            set<int> st({followeeId}) ;
            followersmap.insert({followerId, st}) ;
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followersmap[followerId].find(followeeId) != followersmap[followerId].end()){
            followersmap[followerId].erase(followersmap[followerId].find(followeeId)) ;
        }
    }
};