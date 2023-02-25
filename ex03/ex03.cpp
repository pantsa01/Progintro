#include "pzhelp"
FUNC int gcd (int a, int b){
  a = abs(a); b=abs(b);
  if (a==0 or b==0)
    return a+b;
  else if (a>b)
    return gcd(a%b,b);
  else
    return gcd(a,b%a);
}

PROGRAM{
  int N, i, c, d, e, f, a, b, k, l, m;
  char symbol;
  N=READ_INT();
  FOR (i, 1 TO N STEP 1){
    SKIP_LINE();
    symbol=getchar();
    c=READ_INT();
    d=READ_INT();
    e=READ_INT();
    f=READ_INT();
    if(not(d==0 or f==0 or (symbol=='/' and e==0))){
      switch(symbol){
        case '+':a=(c*f+d*e), b=(d*f);break;
        case '-':a=(c*f-d*e), b=(d*f);break;
        case '*':a=(c*e), b=(d*f);break;
        case '/':a=(c*f), b=(d*e);break;
      }
      if(a/b==0 && (a<0 xor b<0) && (a==0 xor b==0)){
        k=(abs(a)/abs(b));
        l=(abs(a)%abs(b))/gcd(a,b);
        m=abs(b)/gcd(a,b);
        WRITELN(k,l,m);
      }
      else if (a/b==0 && (a<0 xor b<0)){
        k=-(abs(a)/abs(b));
        l=(abs(a)%abs(b))/gcd(a,b);
        m=abs(b)/gcd(a,b);
        WRITE("-");
        WRITELN(k,l,m);
      }
      else if(a/b!=0 && (a<0 xor b<0)){
        k=-(abs(a)/abs(b));
        l=(abs(a)%abs(b))/gcd(a,b);
        m=abs(b)/gcd(a,b);
        WRITELN(k,l,m);
      }
      else{
        k=(abs(a))/(abs(b));
        l=(abs(a)%abs(b))/gcd(a,b);
        m=abs(b)/gcd(a,b);
        WRITELN(k,l,m);
      }
    }
    else{
      WRITELN("error");
    }
  }
}
