#include<bits/stdc++.h>
#include<string>
using namespace std;

class BigInt
{
public:
    int i,carry=0,borrow=0,temp,j;
    string one;

    BigInt(string one)
    {
        this->one=one;
    }
    void Add(BigInt b)
    {
        string one1,two1,ans;
        if(one[0]=='-' && b.one[0]=='-')
        {
            one1=one.substr(1);
            two1=b.one.substr(1);
            one1=erase(one1);
            two1=erase(two1);
            ans=AddAlgo(one1,two1);
            cout<<"-"<<ans<<endl;
        }
        else if(one[0]!='-' && b.one[0]!='-')
        {
            one1=one;
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            ans=AddAlgo(one1,two1);
            cout<<ans<<endl;
        }
        else if(one[0]=='-' && b.one[0]!='-')
        {
            one1=one.substr(1);
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            ans=SubstractionAlgo(two1,one1);
            cout<<ans<<endl;
        }
        else
        {
            one1=one;
            two1=b.one.substr(1);
            one1=erase(one1);
            two1=erase(two1);
            ans=SubstractionAlgo(one1,two1);
            cout<<ans<<endl;
        }
    }
    string AddAlgo(string one1,string two1,int flag=0)
    {
        carry=0;
        int max;
        string ans;
        int l1=one1.length();
        int l2=two1.length();
        int t1=l1;
        int t2=l2;
        if(l1>=l2)
        {
            max=l1;
        }
        else
        {
            max=l2;
        }
        ans.resize(max);
        i=max-1;
        l1--;
        l2--;
        while(l1>=0 && l2>=0)
        {
            temp=(one1[l1]-48)+(two1[l2]-48)+carry;
            carry=temp/10;
            ans[i]=temp%10+48;
            i--;
            l1--;
            l2--;
        }
        if(l1<0 && l2<0)
        {
            if(carry>0 && flag==0)
            {
                ans.resize(max+1);
                string cc=to_string(carry);
                ans=cc+ans;
            }
            if(flag==0)
                ans=erase(ans);
        }
        else if(l1>=0)
        {
            while(l1>=0)
            {
                temp=carry+one1[l1]-48;
                ans[i]=temp%10+48;
                carry=temp/10;
                l1--;
                i--;
            }
            if(carry>0 && flag==0)
            {
                ans.resize(max+1);
                string cc=to_string(carry);
                ans=cc+ans;
            }
            if(flag==0)
                ans=erase(ans);
        }
        else
        {
            while(l2>=0)
            {
                temp=carry+two1[l2]-48;
                ans[i]=temp%10+48;
                carry=temp/10;
                l2--;
                i--;
            }
            if(carry>0 && flag==0)
            {
                ans.resize(max+1);
                string cc=to_string(carry);
                ans=cc+ans;
            }
            if(flag==0)
                ans=erase(ans);
        }
        if(ans.length()==0)
            ans='0';
        return ans;
    }
    void Substraction(BigInt b)
    {
        string one1,two1,ans;
        if(one[0]=='-' && b.one[0]=='-')
        {
            two1=b.one.substr(1);
            one1=one.substr(1);
            one1=erase(one1);
            two1=erase(two1);
            ans=SubstractionAlgo(two1,one1);
            cout<<ans<<endl;
        }
        else if(one[0]!='-' && b.one[0]!='-')
        {
            one1=one;
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            ans=SubstractionAlgo(one1,two1);
            cout<<ans<<endl;
        }
        else if(one[0]=='-' && b.one[0]!='-')
        {
            one1=one.substr(1);
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            ans=AddAlgo(one1,two1);
            cout<<"-"<<ans<<endl;
        }
        else
        {
            one1=one;
            two1=b.one.substr(1);
            one1=erase(one1);
            two1=erase(two1);
            ans=AddAlgo(one1,two1);
            cout<<ans<<endl;
        }
    }
    string SubstractionAlgo(string one1,string two1)
    {
        string ans;
        int s=0;
        if(one1.length()>two1.length())
        {
            string ts=two1;
            two1=one1;
            one1=ts;
            s=1;
        }
        two1=erase(two1);
        if(two1.size()==0)
            return one1;
        two1=complement(two1);
        carry=0;
        ans=AddAlgo(one1,two1,1);
        if(carry==0)
        {
            ans=complement(ans);
            ans=erase(ans);
            if(s==0)
                ans="-"+ans;
            return ans;
        }
        ans=erase(ans);
        if(ans.length()==0)
            ans='0';
        else if(s==1)
            ans="-"+ans;
        return ans;
    }
    string complement(string comp)
    {
        for(i=0;i<comp.size();i++)
        {
            comp[i]=(9-(comp[i]-48))+48;
        }
        carry=0;
        comp=AddAlgo(comp,"1",1);
        return comp;
    }
    string erase(string er)
    {
        int count;
        j=0;count=0;
        while(er[j]==0 || er[j]=='0')
        {
            count++;
            j++;
        }
        if(count>0)
            er.erase(0,count);
        return er;
    }
    void Multiplication(BigInt b)
    {
        string one1,two1,ans;
        if(one[0]=='-' && b.one[0]=='-')
        {
            two1=b.one.substr(1);
            one1=one.substr(1);
            one1=erase(one1);
            two1=erase(two1);
            ans=MultiplicationAlgo(two1,one1);
            cout<<ans<<endl;
        }
        else if(one[0]!='-' && b.one[0]!='-')
        {
            one1=one;
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            ans=MultiplicationAlgo(one1,two1);
            cout<<ans<<endl;
        }
        else if(one[0]=='-' && b.one[0]!='-')
        {
            one1=one.substr(1);
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            ans=MultiplicationAlgo(one1,two1);
            cout<<"-"<<ans<<endl;
        }
        else
        {
            one1=one;
            two1=b.one.substr(1);
            one1=erase(one1);
            two1=erase(two1);
            ans=MultiplicationAlgo(one1,two1);
            cout<<"-"<<ans<<endl;
        }
    }
    string MultiplicationAlgo(string one1,string two1)
    {
        string ans,ans1;
        if(one1.length()<two1.length())
        {
            string st=two1;
            two1=one1;
            one1=st;
        }
        int sz=2*(one1.size()),k;
        ans.resize(sz);
        ans1.resize(sz);
        for(i=0;i<sz;i++)
        {
            ans[i]='0';
            ans1[i]='0';
        }
        carry=0;
        for(int i1=0;i1<two1.length();i1++)
        {
            k=(ans.size()+i1)-two1.length();

            for(j=one1.length()-1;j>=0;j--)
            {
                temp=((one1[j]-48)*(two1[i1]-48))+carry;
                ans[k]=temp%10+48;
                carry=temp/10;
                k--;
            }
            ans[k]=carry+48;
            carry=0;
            if(i1==0)
            {
                ans1=ans;
                for(j=0;j<sz;j++)
                    ans[j]='0';
            }
            else
            {
                ans1=AddAlgo(ans1,ans);
                for(j=0;j<sz;j++)
                    ans[j]='0';
            }
        }
        ans1=erase(ans1);
        if(ans1.length()==0)
            ans1='0';
        return ans1;
    }
    void Division(BigInt b)
    {
        string one1,two1,ans;
        if(one[0]=='-' && b.one[0]=='-')
        {
            two1=b.one.substr(1);
            one1=one.substr(1);
            one1=erase(one1);
            two1=erase(two1);
            ans=DivisionAlgo(one1,two1);
            cout<<ans<<endl;
        }
        else if(one[0]!='-' && b.one[0]!='-')
        {
            one1=one;
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            ans=DivisionAlgo(one1,two1);
            cout<<ans<<endl;
        }
        else if(one[0]=='-' && b.one[0]!='-')
        {
            one1=one.substr(1);
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            ans=DivisionAlgo(one1,two1);
            cout<<"-"<<ans<<endl;
        }
        else
        {
            one1=one;
            two1=b.one.substr(1);
            one1=erase(one1);
            two1=erase(two1);
            ans=DivisionAlgo(one1,two1);
            cout<<"-"<<ans<<endl;
        }
    }
    string DivisionAlgo(string one1,string two1)
    {
        string ans;
        two1=erase(two1);
        if(two1.size()==0)
            return "Divisible by zero";
        ans.resize(one1.length()+1);
        for(i=0;i<ans.size();i++)
            ans[i]='0';
        while(one1[0]!='-')
        {
            one1=SubstractionAlgo(one1,two1);
            ans=AddAlgo(ans,"1",1);
        }
        ans=SubstractionAlgo(ans,"1");
        return ans;
    }
    void GCD(BigInt b)
    {
        string one1,two1,ans;
        if(one[0]=='-' || b.one[0]=='-')
        {
            cout<<"0"<<endl;
        }
        else
        {
            one1=one;
            two1=b.one;
            one1=erase(one1);
            two1=erase(two1);
            if(one1.size()==0 || two1.size()==0)
                cout<<"0"<<endl;
            else
            {
                ans=GCDAlgo(one1,two1);
                cout<<ans<<endl;
            }
        }
    }
    int zero(string x)
    {
        string a=erase(x);
        if(a.size()==0)
            return 0;
        else 
            return 1;
    }
    string GCDAlgo(string one1,string two1)
    {
        if(zero(one1)==0)
            return two1;
        else
        {
            string ans=DivisionAlgo(two1,one1);
            string ans1=MultiplicationAlgo(ans,one1);
            string ans2=SubstractionAlgo(two1,ans1);
            return GCDAlgo(ans2,one1);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    string sa,sb;
    int t,k;
    cin>>t;
    while(t--)
    {
        cin>>sa;
        cin>>sb;
        BigInt b1(sa),b2(sb);
        cin>>k;
        if(k==1)
            b1.Add(b2);
        else if(k==2)
            b1.Substraction(b2);
        else if(k==3)
            b1.Multiplication(b2);
        else if(k==4)
            b1.Division(b2);
        else
            b1.GCD(b2);
    }
    return 0;
}