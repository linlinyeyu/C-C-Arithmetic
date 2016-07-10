    #include<cstdio>  
    #include<cstring>  
    #include<iostream>  
    #include<algorithm>  
    using namespace std;  
    const int maxn=65;  
    int n,a[maxn],sum[maxn];  
    bool vis[maxn],getans;  
    void DFS(int res,int now,int val,int st)  
    {  
        if(res==val||getans)  
        {  
        getans=1;  
        return;  
        }  
        int last=-1;  
        for(int i=st;i>=1;i--)  
        {  
        if(!vis[i])  
        {  
            if(a[i]==last)  
            continue;  
            if(now+a[i]<val)  
            {  
            vis[i]=1;  
            DFS(res-a[i],now+a[i],val,i-1);  
            if(getans)  
                return;  
            vis[i]=0;  
            last=a[i];  
            }  
            else if(now+a[i]==val)  
            {  
            vis[i]=1;  
            DFS(res-a[i],0,val,n);  
            if(getans)  
                return;  
            vis[i]=0;  
            last=a[i];  
            }  
            if(!now)  
            return;  
        }  
        }  
    }  
    int main()  
    {  
        while(scanf("%d",&n)&&n)  
        {  
        getans=0;  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d",&a[i]);  
            sum[i]=sum[i-1]+a[i];  
        }  
        sort(a+1,a+n+1);  
        for(int i=n;i>=1;i--)  
        {  
            if(sum[n]%i==0)  
            {  
            if(sum[n]/i<a[n])  
                continue;  
            memset(vis,0,sizeof(vis));  
            DFS(sum[n],0,sum[n]/i,n);  
            if(getans)  
            {  
                printf("%d\n",sum[n]/i);  
                break;  
            }  
            }  
        }  
        }  
        return 0;  
    }  
