#include <stdio.h>
#include <memory.h>
#include <string>
#include <algorithm>
#define MX 256
using namespace std;
pair<int,int> f(string &s, int p)
{
              if (p < s.size()) {
                    if (s[p] == '?') {
                       if (s.size() == 1) return make_pair(0,9);
                       return make_pair(p==s.size()-1,9);
                    }
                    else return make_pair(s[p]-'0',s[p]-'0');
              }
              else return make_pair(0,0);
}
string a, b, c; // a + b = c
string ra[2], rb[2], rc[2], nra[2], nrb[2], nrc[2];
int op;
char str[MX];
int can[MX][2], _can[MX][2];
int CAN(int p, int u)
{
    if (p < 0) return u == 0;
    if (_can[p][u]) return can[p][u];
    _can[p][u] = 1; can[p][u] = 0;
    int i, j, k;
    int is, ie, js, je, ks, ke;
    
    is = f(a,p).first; ie = f(a,p).second;
    js = f(b,p).first; je = f(b,p).second;
    ks = f(c,p).first; ke = f(c,p).second;
    for (i = is; i <= ie; i++) {
        for (j = js; j <= je; j++) {
            for (k = ks; k <= ke; k++) {
                if (u == 0) {
                   if (i+j == k) {
                      if (CAN(p-1,0)) can[p][u] = 1;                      
                   }
                   else if (i+j+1 == k) {
                        if (CAN(p-1,1)) can[p][u] = 1;
                   }
                }
                else {
                     if (i+j == k+10) {
                        if (CAN(p-1,0)) can[p][u] = 1;
                     }
                     else if (i+j+1 == k+10) {
                          if (CAN(p-1,1)) can[p][u] = 1;
                     }
                }
            }
        }
    }
    return can[p][u];
}
int main()
{
    FILE *in=fopen("input.txt","r");
    FILE *out=fopen("output.txt","w");
    int t, T, p, u, i, j, k, uu;
    int is, ie, js, je, ks, ke;
    string asdf;
    
    fscanf(in,"%d",&T);
    for (t = 1; t <= T; t++) {
        fprintf(out,"Case #%d: ",t);
        fscanf(in,"%s",str);
        a = ""; for (i = strlen(str)-1; i >= 0; i--)a += str[i];
        fscanf(in,"%s",str);
        if (str[0] == '+') op = 0;
        else op = 1;
        fscanf(in,"%s",str);
        b = ""; for (i = strlen(str)-1; i >= 0; i--) b += str[i];
        fscanf(in,"%s",str);
        fscanf(in,"%s",str);
        c = ""; for (i = strlen(str)-1; i >= 0; i--) c += str[i];
        if (op == 1) swap(a,c);
        memset(_can,0,sizeof(_can));
        p = 0;
        if (p < a.size()) p = a.size();
        if (p < b.size()) p = b.size();
        if (p < c.size()) p = c.size();
        ra[0] = a; rb[0] = b; rc[0] = c;
        ra[1] = ""; rb[1] = ""; rc[1] = "";        
        if (op == 0) {
               for (p--; p >= 0; p--) {
                   nra[0] = ""; nrb[0] = ""; nrc[0] = "";
                   nra[1] = ""; nrb[1] = ""; nrc[1] = "";
                   for (u = 0; u < 2; u++) {
                   if (ra[u] == "") continue;
                   is = f(a,p).first; ie = f(a,p).second;
                   js = f(b,p).first; je = f(b,p).second;
                   ks = f(c,p).first; ke = f(c,p).second;
//                   fprintf(out,"p = %d, u = %d\n",p,u);
//                   fprintf(out,"ra[u] = %s, rb[u] = %s, rc[u] = %s\n",ra[u].c_str(),rb[u].c_str(),rc[u].c_str());
//                   fprintf(out,"is = %d, ie = %d\n",is,ie);
//                   fprintf(out,"js = %d, je = %d\n",js,je);
//                   fprintf(out,"ks = %d, ke = %d\n",ks,ke);
                   for (i = is; i <= ie; i++) {
                       for (j = js; j <= je; j++) {
                           for (k = ks; k <= ke; k++) {
                               if (u == 0) {
                                     if (i+j == k) {
                                        if (!CAN(p-1,0)) continue;
                                        uu = 0;
                                     }
                                     else if (i+j+1 == k) {
                                          if (!CAN(p-1,1)) continue;
                                          uu = 1;
                                     }
                                     else continue;
                               }
                               else {
                                    if (i+j == k+10) {
                                       if (!CAN(p-1,0)) continue;
                                       uu = 0;
                                    }
                                    else if (i+j+1 == k+10) {
                                         if (!CAN(p-1,1)) continue;
                                         uu = 1;
                                    }
                                    else continue;
                               }
                               if (nra[uu] == "") goto maki;
                               asdf = ra[u];
                               if (p < a.size()) asdf[p] = i+'0';
                               reverse(asdf.begin(),asdf.end());
                               reverse(nra[uu].begin(),nra[uu].end());
                               if (asdf > nra[uu]) {
                                  reverse(nra[uu].begin(),nra[uu].end());
                                  continue;
                               }
                               if (asdf < nra[uu]) {
                                  reverse(nra[uu].begin(),nra[uu].end());
                                  goto maki;
                               }
                               reverse(nra[uu].begin(),nra[uu].end());
                               asdf = rb[u];
                               if (p < b.size()) asdf[p] = j+'0';
                               reverse(asdf.begin(),asdf.end());
                               reverse(nrb[uu].begin(),nrb[uu].end());
                               if (asdf > nrb[uu]) {
                                  reverse(nrb[uu].begin(),nrb[uu].end());
                                  continue;
                               }
                               if (asdf < nrb[uu]) {
                                  reverse(nrb[uu].begin(),nrb[uu].end());
                                  goto maki;
                               }
                               reverse(nrb[uu].begin(),nrb[uu].end());
                               asdf = rc[u];
                               if (p < c.size()) asdf[p] = k+'0';
                               reverse(asdf.begin(),asdf.end());
                               reverse(nrc[uu].begin(),nrc[uu].end());
                               if (asdf > nrc[uu]) {
                                  reverse(nrc[uu].begin(),nrc[uu].end());
                                  continue;
                               }
                               if (asdf < nrc[uu]) {
                                  reverse(nrc[uu].begin(),nrc[uu].end());
                                  goto maki;
                               }
                               reverse(nrc[uu].begin(),nrc[uu].end());
maki:                               
//                               fprintf(out,"%d %d %d\n",i,j,k);
                                 nra[uu] = ra[u];
                               if (p < a.size()) nra[uu][p] = i+'0';
                                  nrb[uu] = rb[u];                               
                               if (p < b.size()) nrb[uu][p] = j+'0';
                                  nrc[uu] = rc[u];
                               if (p < c.size()) nrc[uu][p] = k+'0';
                           }
                       }
                   }
                   }                   
                   ra[0] = nra[0]; rb[0] = nrb[0]; rc[0] = nrc[0];
                   ra[1] = nra[1]; rb[1] = nrb[1]; rc[1] = nrc[1];
               }
               a = ra[0]; b = rb[0]; c = rc[0];
               for (i = a.size()-1; i >= 0; i--) fprintf(out,"%c",a[i]);
               fprintf(out," + ");
               for (i = b.size()-1; i >= 0; i--) fprintf(out,"%c",b[i]);
               fprintf(out," = ");
               for (i = c.size()-1; i >= 0; i--) fprintf(out,"%c",c[i]);
               fprintf(out,"\n");
        }
        else { // str : c - b = a
               for (p--; p >= 0; p--) {
                   nra[0] = ""; nrb[0] = ""; nrc[0] = "";
                   nra[1] = ""; nrb[1] = ""; nrc[1] = "";
                   for (u = 0; u < 2; u++) {
                   if (ra[u] == "") continue;
                   is = f(a,p).first; ie = f(a,p).second;
                   js = f(b,p).first; je = f(b,p).second;
                   ks = f(c,p).first; ke = f(c,p).second;
//                   fprintf(out,"p = %d, u = %d\n",p,u);
//                   fprintf(out,"is = %d, ie = %d\n",is,ie);
//                   fprintf(out,"js = %d, je = %d\n",js,je);
//                   fprintf(out,"ks = %d, ke = %d\n",ks,ke);
                   for (i = is; i <= ie; i++) {
                       for (j = js; j <= je; j++) {
                           for (k = ks; k <= ke; k++) {
                               if (u == 0) {
                                     if (i+j == k) {
                                        if (!CAN(p-1,0)) continue;
                                        uu = 0;
                                     }
                                     else if (i+j+1 == k) {
                                          if (!CAN(p-1,1)) continue;
                                          uu = 1;
                                     }
                                     else continue;
                               }
                               else {
                                    if (i+j == k+10) {
                                       if (!CAN(p-1,0)) continue;
                                       uu = 0;
                                    }
                                    else if (i+j+1 == k+10) {
                                         if (!CAN(p-1,1)) continue;
                                         uu = 1;
                                    }
                                    else continue;
                               }
                               if (nra[uu] == "") goto maki2;
                               asdf = rc[u];
                               if (p < c.size()) asdf[p] = k+'0';
                               reverse(asdf.begin(),asdf.end());
                               reverse(nrc[uu].begin(),nrc[uu].end());
                               if (asdf > nrc[uu]) {
                                  reverse(nrc[uu].begin(),nrc[uu].end());
                                  continue;                              
                               }   
                               if (asdf < nrc[uu]) {
                                  reverse(nrc[uu].begin(),nrc[uu].end());
                                  goto maki2;
                               } 
                               reverse(nrc[uu].begin(),nrc[uu].end());
                               asdf = rb[u];
                               if (p < b.size()) asdf[p] = j+'0';
                               reverse(asdf.begin(),asdf.end());
                               reverse(nrb[uu].begin(),nrb[uu].end());
                               if (asdf > nrb[uu]) {
                                  reverse(nrb[uu].begin(),nrb[uu].end());
                                  continue;
                               }
                               if (asdf < nrb[uu]) {
                                  reverse(nrb[uu].begin(),nrb[uu].end());
                                  goto maki2;
                               }
                               reverse(nrb[uu].begin(),nrb[uu].end());
                               asdf = ra[u];
                               if (p < a.size()) asdf[p] = i+'0';
                               reverse(asdf.begin(),asdf.end());
                               reverse(nra[uu].begin(),nra[uu].end());
                               if (asdf > nra[uu]) {
                                  reverse(nra[uu].begin(),nra[uu].end());
                                  continue;
                               }
                               if (asdf < nra[uu]) {
                                  reverse(nra[uu].begin(),nra[uu].end());
                                  goto maki2;
                               }
                               reverse(nra[uu].begin(),nra[uu].end());
//                               fprintf(out,"%d %d %d\n",i,j,k);
maki2:
                                 nra[uu] = ra[u];
                               if (p < a.size()) nra[uu][p] = i+'0';
                                  nrb[uu] = rb[u];                               
                               if (p < b.size()) nrb[uu][p] = j+'0';
                                  nrc[uu] = rc[u];
                               if (p < c.size()) nrc[uu][p] = k+'0';
                           }
                       }
                   }
                   }                   
                   ra[0] = nra[0]; rb[0] = nrb[0]; rc[0] = nrc[0];
                   ra[1] = nra[1]; rb[1] = nrb[1]; rc[1] = nrc[1];
               }
               a = ra[0]; b = rb[0]; c = rc[0];               
               for (i = c.size()-1; i >= 0; i--) fprintf(out,"%c",c[i]);
               fprintf(out," - ");
               for (i = b.size()-1; i >= 0; i--) fprintf(out,"%c",b[i]);
               fprintf(out," = ");
               for (i = a.size()-1; i >= 0; i--) fprintf(out,"%c",a[i]);
               fprintf(out,"\n");     
        }
        printf("%d\n",t);
    }
    return 0;
}
