import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class Main
{
HashMap < String, String > statements = new HashMap <> ();
List < String > result = new ArrayList < String > (Arrays.asList ("T1", "T3", "T2", "T5", "T6"));
List < String > operators =
new ArrayList < String > (Arrays.asList ("+", "*"));
public static void main (String[]args)
{
Main obj = new Main();
obj.getStatements ();
System.out.println ("Initaially statements are: ");
obj.putStatements ();
obj.constantFolding ();
System.out.println ("After constant folding: ");
obj.putStatements ();
obj.variablePropagation ();
System.out.println ("After variable propagation: ");
obj.putStatements ();
obj.commonSubexpElim ();
System.out.println ("After Common Sub-expression Elimination: ");
obj.putStatements ();
}
public void getStatements ()
{
this.statements.put ("T1", "5*3+10");
this.statements.put ("T3", "T1");
this.statements.put ("T2", "T1+T3");


this.statements.put ("T5", "4*T2");
this.statements.put ("T6", "4*T2+100");
}
public void putStatements ()
{
for (Map.Entry mapElement:this.statements.entrySet ())
{
String key = (String) mapElement.getKey ();
String value = (String) mapElement.getValue ();
System.out.println (key + " : " + value);
}
System.out.println ("----------------------------------------");
}
public int evaluate (String str)
{
String[]arr = str.split ("\\+");
for (int i = 0; i < arr.length; i++)
{
int result = 1;
if (arr[i].contains ("*"))
{
String[]num = arr[i].split ("\\*");
for (int j = 0; j < num.length; j++)
{
result *= Integer.parseInt (num[j]);
}
arr[i] = String.valueOf (result);
}
}
int len = arr.length;
int sum = 0;
for(int i = 0; i < len; i++)
{
sum += Integer.parseInt (arr[i]);
}
return sum;
}
public void constantFolding ()
{
for (int i = 0; i < this.result.size (); i++)
{
String lhs = this.result.get (i);
String rhs = this.statements.get (lhs);
Pattern p = Pattern.compile ("[\\d]+([+*][\\d]+)+");

Matcher m = p.matcher (rhs);
while (m.find ())
{
String subexpr = m.group ();
int result = this.evaluate (subexpr);
String res = String.valueOf (result);
rhs = rhs.replace (rhs.substring (m.start (), m.end ()), res);
m = p.matcher (rhs);
}
this.statements.put (lhs, rhs);
}
}
public void variablePropagation ()
{
for (int i = 0; i < this.result.size (); i++)
{
String lhs1 = this.result.get (i);
String rhs1 = this.statements.get (lhs1);
if (rhs1.length () == 1 && this.result.contains (rhs1))
{
for (int j = 0; j < this.result.size (); j++)
{
String lhs2 = this.result.get (j);
String rhs2 = this.statements.get (lhs2);
if (rhs2.contains (lhs1))
{
rhs2 = rhs2.replace (lhs1, rhs1);
this.statements.put (lhs2, rhs2);
}
}
this.result.remove (lhs1);
this.statements.remove (lhs1, rhs1);
}
}
}
public void commonSubexpElim ()
{
for (int i = 0; i < this.result.size (); i++)
{
String lhs1 = this.result.get (i);
String rhs1 = this.statements.get (lhs1);
for (int j = 0; j < this.result.size (); j++)
{
String lhs2 = this.result.get (j);

String rhs2 = this.statements.get (lhs2);
if (lhs1 == lhs2)
{
continue;
}
if (rhs1.contains (rhs2))
{
int start = rhs1.indexOf (rhs2);
int len = rhs2.length ();
rhs1 = rhs1.replace(rhs1.substring(start,len),lhs2);
this.statements.put(lhs1,rhs1);
}
}
}
}
}

/*
To check if javac is installed
javac --version
To run the prog in cmd
javac Filename.java
java Filename
 */

 