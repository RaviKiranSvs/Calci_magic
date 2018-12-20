#include<Keypad.h>
#include<LiquidCrystal.h>

char a[4][4]= {{'1','2','3','A'},{'4','5','6','B'},
{'7','8','9','C'},{'*','0','#','D'}};

byte r[4]={5,4,3,2};
byte c[4]={A0,A1,A2,A3};

Keypad k=Keypad(makeKeymap(a),r,c,4,4);

LiquidCrystal cal(7,6,11,10,9,8);

char b,s='+';
int d1=0,d2=0;

void setup()
{
  cal.begin(16,2);
}

void loop()
{
  b=k.getKey();

  if(b=='A')
  {
    s='+';
    cal.clear();
    cal.print(s);
    d2=d1+d2;
    d1=0;
  }

  if(b=='B')
  {
    s='-';
    cal.clear();
    cal.print(s);
    d2=d2+d1;
    d1=0;
  }

  if(b>='0'&&b<='9')
  {
    if(d1==0) d2==0;
    
    if(s=='+')
    {
      cal.clear();
      d1=(int)d1*10+(b-48);
      cal.print(d1);
    }

    else if(s=='-')
    {
      cal.clear();
      d1=(int)-(-d1*10+(b-48));
      cal.print(-d1);
    }
  }

  if(b=='C')
  {
    if(s=='+'||s=='-')
    {
      cal.clear();
      d2=d1+d2;
      cal.print(d2);
      d1=0;
      //d2=0;
      s='+';
    }
  }

}

