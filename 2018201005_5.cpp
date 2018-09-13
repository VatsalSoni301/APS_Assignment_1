#include<bits/stdc++.h>
#define ll long long
using namespace std;

void InsertMaxHeap(vector<ll> &arr,ll len);
void InsertMinHeap(vector<ll> &arr,ll len);
void MaxHeapify(vector<ll> &arr,ll i,ll len);
void MinHeapify(vector<ll> &arr,ll i,ll len);
int main()
{
    ll n,i,smin2=0,smax2=0;
    cin>>n;
    vector<ll> arr(n+1),arrmax(n+1),arrmin(n+1);
    double ans[n+1],mid=0;
    arr[0]=0;
    ans[0]=0;
    arrmax[0]=1000005;
    arrmin[0]=-1000005;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        
        if(arr[i]>=mid)
        {
            if(smin2==smax2)
            {
                arrmin[++smin2]=arr[i];
                //MinHeapify(arrmin,smin2/2,smin2);
                InsertMinHeap(arrmin,smin2);
                mid=arrmin[1];
                ans[i]=mid;
            }
            else if(smin2>smax2)
            {
                arrmax[++smax2]=arrmin[1];
                arrmin[1]=arrmin[smin2];
                smin2--;
                //MaxHeapify(arrmax,smax2/2,smax2);
                InsertMaxHeap(arrmax,smax2);
                MinHeapify(arrmin,1,smin2);
                arrmin[++smin2]=arr[i];
                //MinHeapify(arrmin,smin2/2,smin2);
                InsertMinHeap(arrmin,smin2);
                ans[i]=(arrmax[1]+arrmin[1])/2.0;
                mid=ans[i];
            }
            else
            {
                arrmin[++smin2]=arr[i];
                InsertMinHeap(arrmin,smin2);
                //MinHeapify(arrmin,smin2/2,smin2);
                mid=(arrmin[1]+arrmax[1])/2.0;
                ans[i]=mid;
            }
        }
        else
        {
            if(smin2==smax2)
            {
                arrmax[++smax2]=arr[i];
                InsertMaxHeap(arrmax,smax2);
                //MaxHeapify(arrmax,smax2/2,smax2);
                mid=arrmax[1];
                ans[i]=mid;
            }
            else if(smax2>smin2)
            {
                arrmin[++smin2]=arrmax[1];
                arrmax[1]=arrmax[smax2];
                smax2--;
                //MinHeapify(arrmin,smin2/2,smin2);
                InsertMinHeap(arrmin,smin2);
                MaxHeapify(arrmax,1,smax2);
                arrmax[++smax2]=arr[i];
                //MaxHeapify(arrmax,smax2/2,smax2);
                InsertMaxHeap(arrmax,smax2);
                ans[i]=(arrmin[1]+arrmax[1])/2.0;
                mid=ans[i];
            }
            else
            {
                arrmax[++smax2]=arr[i];
                //MaxHeapify(arrmax,smax2/2,smax2);
                InsertMaxHeap(arrmax,smax2);
                mid=(arrmin[1]+arrmax[1])/2.0;
                ans[i]=mid;
            }
          }  
        
        /*cout<<endl<<"Min"<<"=";
        for(i=1;i<=smin2;i++)
            cout<<arrmin[i]<<" ";
        cout<<endl<<"Max"<<"=";
        for(i=1;i<=smax2;i++)
            cout<<arrmax[i]<<" ";
        cout<<endl<<"mid="<<mid;
        char x;
        cin>>x;*/
    }
    for(i=1;i<=n;i++)
        cout<<fixed<<setprecision(1)<<ans[i]<<endl;
    return 0;
}
void MaxHeapify(vector<ll> &arr,ll i,ll len)
{
    ll max=0;
    ll a=2*i;
    ll b=2*i+1;
    if(a<=len && arr[i]<arr[a])
        max=a;
    else
        max=i;
    if(b<=len && arr[max]<arr[b])
        max=b;
    if(max!=i)
    {
        ll temp=arr[max];
        arr[max]=arr[i];
        arr[i]=temp;
        MaxHeapify(arr,max,len);
    }
}
void MinHeapify(vector<ll> &arr,ll i,ll len)
{
    ll min=0;
    ll a=2*i;
    ll b=2*i+1;
    if(a<=len && arr[i]>arr[a])
        min=a;
    else
        min=i;
    if(b<=len && arr[min]>arr[b])
        min=b;
    if(min!=i)
    {
        ll temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        MinHeapify(arr,min,len);
    }
}
void InsertMaxHeap(vector<ll> &arr,ll n)
{
    int i=n/2;
    while (i>0 && arr[i]<arr[n])
    {
        ll t=arr[i];
        arr[i]=arr[n];
        arr[n]=t;
        n=i;
        i=i/2;
    }
}
void InsertMinHeap(vector<ll> &arr,ll n)
{
    int i=n/2;
    while (i>0 && arr[i]>arr[n])
    {
        ll t=arr[i];
        arr[i]=arr[n];
        arr[n]=t;
        n=i;
        i=i/2;
    }
}