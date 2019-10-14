#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
char t1[1111];
char t2[1111];
char t3[1111];
char type;
string a,b,c;
class rock {
public:
    string t1,t2,t3;
    bool gg;
    rock() {
        t1="";
        t2="";
        t3="";
        gg=false;
    }
};

bool operator == (const rock &u, const rock &v) {
    if (u.t1 == v.t1 && u.t2 == v.t2 && u.t3 == v.t3)
        return true;
    else
        return false;
}

map<pair<int,int>,rock> d;

rock go(int x, int carry) {
    if (x == 0) {
        if (carry) {
            rock tmp;
            tmp.gg = true;
            return tmp;
        } else {
            return rock();
        }
    }
    if (d.count(make_pair(x,carry)))
        return d[make_pair(x,carry)];

    rock &ans = d[make_pair(x,carry)];

    ans.gg = true;

    for (int l1=0; l1<10; l1++) {
        for (int l2=0; l2<10; l2++) {
            for (int l3=0; l3<10; l3++) {
                if (x > a.size()) {
                    if (l1>0) continue;
                } else {
                    int aa = (int)a.size()-x;
                    if (aa==0 && l1==0 && a.size()>1) continue;
                    if(a[aa] != '?' && a[aa] != l1+'0') continue;
                }
                if (x>b.size()) {
                    if (l2>0) continue;
                } else {
                    int bb=(int)b.size()-x;
                    if (bb==0 && l2==0 && b.size()>1) continue;
                    if(b[bb]!='?' && b[bb]!=l2+'0') continue;
                }
                if(x>c.size()) {
                    if (l3>0) continue;
                } else {
                    int cc = (int)c.size()-x;
                    if (cc==0 && l3==0 && c.size()>1) continue;
                    if (c[cc]!='?' && c[cc]!=l3+'0') continue;
                }
                for (int l4=0; l4<2; l4++) {
                    if (l4 == 0) {
                    }
                    if ((l1+l2+l4)/10 != carry) continue;
                    if ((l1+l2+l4)%10 != l3) continue;

                    rock temp = go(x-1,l4);
                    if(temp.gg) continue;
                    temp.t1 = (char)(l1+'0')+temp.t1;
                    temp.t2 = (char)(l2+'0')+temp.t2;
                    temp.t3 = (char)(l3+'0')+temp.t3;
                    if (ans.gg) {
                        ans = temp;
                        ans.gg = false;
                    } else if (ans.t1 > temp.t1) {
                        ans = temp;
                        ans.gg = false;
                    } else if (ans.t1 == temp.t1 && ans.t2 > temp.t2) {
                        ans = temp;
                        ans.gg =false;
                    } else if (ans.t1 == temp.t1 && ans.t2 == temp.t2 && ans.t3 > temp.t3) {
                        ans = temp;
                        ans.gg=false;
                    }
                }
            }
        }
    }
    return ans;

}
rock gogo(int x, int carry) {
    if (x == 0) {
        if (carry) {
            rock tmp;
            tmp.gg = true;
            return tmp;
        } else {
            return rock();
        }
    }
    if (d.count(make_pair(x,carry)))
        return d[make_pair(x,carry)];

    rock &ans = d[make_pair(x,carry)];

    ans.gg = true;

    for (int l1=0; l1<10; l1++) {
        for (int l2=0; l2<10; l2++) {
            for (int l3=0; l3<10; l3++) {
                if (x > a.size()) {
                    if (l1>0) continue;
                } else {
                    int aa = (int)a.size()-x;
                    if (aa==0 && l1==0 && a.size()>1) continue;
                    if(a[aa] != '?' && a[aa] != l1+'0') continue;
                }
                if (x>b.size()) {
                    if (l2>0) continue;
                } else {
                    int bb=(int)b.size()-x;
                    if (bb==0 && l2==0 && b.size()>1) continue;
                    if(b[bb]!='?' && b[bb]!=l2+'0') continue;
                }
                if(x>c.size()) {
                    if (l3>0) continue;
                } else {
                    int cc = (int)c.size()-x;
                    if (cc==0 && l3==0 && c.size()>1) continue;
                    if (c[cc]!='?' && c[cc]!=l3+'0') continue;
                }
                for (int l4=0; l4<2; l4++) {
                    if ((l1+l2+l4)/10 != carry) continue;
                    if ((l1+l2+l4)%10 != l3) continue;

                    rock temp = gogo(x-1,l4);
                    if(temp.gg) continue;
                    temp.t1 = (char)(l1+'0')+temp.t1;
                    temp.t2 = (char)(l2+'0')+temp.t2;
                    temp.t3 = (char)(l3+'0')+temp.t3;
                    if (ans.gg) {
                        ans = temp;
                        ans.gg = false;
                    } else if (ans.t3 > temp.t3) {
                        ans = temp;
                        ans.gg = false;
                    } else if (ans.t3 == temp.t3 && ans.t1 > temp.t1) {
                        ans = temp;
                        ans.gg =false;
                    } else if (ans.t3 == temp.t3 && ans.t1 == temp.t1 && ans.t2 > temp.t2) {
                        ans = temp;
                        ans.gg=false;
                    }
                }
            }
        }
    }
    return ans;

}

string trim(string s) {
    while(s.size()>1 && s[0] =='0') {
        s.erase(0,1);
    }
    return s;
}

int main() {
    int t;
    scanf("%d\n",&t);
    for (int tc=1; tc<=t; tc++) {
        scanf("%s %c %s = %s\n",t1,&type,t2,t3);
        a=t1;
        b=t2;
        c=t3;
        d.clear();
        rock ans;
        if (type == '+')
            ans = go(c.size(),0);       
        else {
            string tt = a;
            a=b;
            b=c;
            c=tt;
            ans = gogo(c.size(),0);
            tt = ans.t3;
            ans.t3=ans.t2;
            ans.t2=ans.t1;
            ans.t1=tt;
        }
        ans.t1=trim(ans.t1);
        ans.t2=trim(ans.t2);
        ans.t3=trim(ans.t3);
        printf("Case #%d: %s %c %s = %s\n",tc,ans.t1.c_str(),type,ans.t2.c_str(),ans.t3.c_str());
    }
    return 0;
}
