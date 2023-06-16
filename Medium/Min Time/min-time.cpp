//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   long long dp[100001][2];
   void fun(int indx,int tar,int prev,int it,int temp,int state_old,int state_new)
   {/*
   indx->pivot[left or right extreme of previous layer]
   tar->left or right extreme of current layer
   prev->previous layer
   it->current layer
   temp->complimentary of tar[f tar is left extreme than this is right extreme and viceversa]
   state_old->0 for left extreme,1 for right extreme of previous layer
   state_new->same as prev for current layer*/
   
       if(state_new==0)
       {
           if(indx>=temp)
           dp[it][0]=min(dp[it][0],dp[prev][state_old]+indx-tar);
           else if(indx<=tar)
           dp[it][0]=min(dp[it][0],dp[prev][state_old]+temp-indx+temp-indx-(tar-indx));
           else
           dp[it][0]=min(dp[it][0],(dp[prev][state_old]+2*1ll*(temp-indx)+indx-tar));
       }
        if(state_new==1)
       {
           
           if(indx<=temp)
           dp[it][1]=min(dp[it][1],dp[prev][state_old]+tar-indx);
           else if(indx>=tar)
           dp[it][1]=min(dp[it][1],dp[prev][state_old]-temp+indx-temp+indx-(-tar+indx));
           else
           {dp[it][1]=min(dp[it][1],dp[prev][state_old]+2*(-temp+indx)-indx+tar);
               
              
           }
           
       }
   }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
       
        vector<int>v[100001];
        int maxx=0,minn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            v[types[i]].push_back(locations[i]);
            maxx=max(maxx,types[i]);
            minn=min(minn,types[i]);
        }
        for(int i=0;i<=maxx;i++)
        {
            dp[i][0]=1e15;
            dp[i][1]=1e15;
        }
            sort(v[minn].begin(),v[minn].end());
        if(v[minn].back()<=0)
        {
            dp[minn][1]=2*abs(v[minn][0])-abs(v[minn].back());
            dp[minn][0]=abs(v[minn][0]);
      
        }
          if(v[minn][0]<0&&v[minn].back()>0)
        {
            
            dp[minn][0]=2*abs(v[minn].back())+abs(v[minn][0]);
            dp[minn][1]=abs(2*v[minn][0])+abs(v[minn].back());
        }
        if(v[minn][0]>=0)
        {
            dp[minn][0]=2*abs(v[minn].back())-abs(v[minn][0]);
            dp[minn][1]=v[minn].back();
        
        }
        set<int>s;
        for(auto &it:types)
        s.insert(it);
        s.erase(s.begin());
        int prev=minn;
        for(auto &it:s)
        {
            sort(v[it].begin(),v[it].end());
            int lo=v[prev][0];
            int hi=v[prev].back();
            int new_lo=v[it][0];
            int new_hi=v[it].back();
            fun(lo,new_lo,prev,it,new_hi,0,0);
            fun(lo,new_hi,prev,it,new_lo,0,1);
            fun(hi,new_lo,prev,it,new_hi,1,0);
            fun(hi,new_hi,prev,it,new_lo,1,1);
            
            
            
            prev=it;
            
        }

        return min(dp[maxx][0]+abs(v[maxx][0]),dp[maxx][1]+abs(v[maxx].back()));
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends