#define LemReserves 100
#include <string.h>
#include <stdio.h>

int HashFunc(char* word)
{
	return (int)word % LemReserves;
	
}
typedef struct Uniform
{
	char* str;
	Uniform* next;
}Uniform;
typedef struct original
{
	char* str;
	//מצביע למקום בקוד
	original* next;
}original;
void HashTable(){
	
	Uniform HashUniform[100];
	HashUniform[HashFunc("else")].str="else";
	HashUniform[HashFunc("if")].str = "if";
	HashUniform[HashFunc("not")].str = "not";
	HashUniform[HashFunc("fun")].str = "fun";
	HashUniform[HashFunc("loop")].str = "loop";
	HashUniform[HashFunc("return")].str = "return";
	HashUniform[HashFunc("print")].str = "print";
	HashUniform[HashFunc("input")].str = "input";
	HashUniform[HashFunc("global")].str = "global"; 
	HashUniform[HashFunc("define")].str = "define";
	HashUniform[HashFunc("static")].str = "static";
	HashUniform[HashFunc("class")].str = "class"; 
	HashUniform[HashFunc("next")].str = "next"; 
	HashUniform[HashFunc("break")].str = "break";
	HashUniform[HashFunc(")")].str = ")";
	HashUniform[HashFunc("(")].str = "(";
	HashUniform[HashFunc("}")].str = "}";
	HashUniform[HashFunc("{")].str = "{";
	HashUniform[HashFunc("]")].str = "]";
	HashUniform[HashFunc("[")].str = "[";
	HashUniform[HashFunc("true")].str = "true";
	HashUniform[HashFunc("false")].str = "false"; 
	HashUniform[HashFunc("=")].str = "=";
	HashUniform[HashFunc("!=")].str = "!=";
	HashUniform[HashFunc("<")].str = "<";
	HashUniform[HashFunc(">")].str = ">";
	HashUniform[HashFunc("<=")].str = "<=";
	HashUniform[HashFunc(">=")].str = ">=";
	HashUniform[HashFunc(",")].str = ",";
	HashUniform[HashFunc(";")].str = ";";
	HashUniform[HashFunc("/n")].str = "/n";
	HashUniform[HashFunc("/t")].str = "/t";
	HashUniform[HashFunc("+")].str = "+"; 
	HashUniform[HashFunc("-")].str = "-";
	HashUniform[HashFunc("*")].str = "*";
	HashUniform[HashFunc("/")].str = "/";
	HashUniform[HashFunc("%")].str = "%";
	HashUniform[HashFunc("&")].str = "&";
	HashUniform[HashFunc("|")].str = "|";


}
