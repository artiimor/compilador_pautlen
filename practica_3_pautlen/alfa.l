/*Definiciones*/
/*Declaraciones de variables, funciones y #include*/
%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"

int line = 0;
int col = 0;
char tokcad[25];
char *tok;
extern FILE* fout;
%}

%option noyywrap
DIGITO			[0-9]
LETRA			[a-zA-Z]
ENTERO			{DIGITO}*
COMENTARIO		"//".*\n
IDENTIFICADOR 	{LETRA}({LETRA}|{DIGITO})*


%%
main        {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_MAIN;}
int         {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_INT;}
boolean     {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_BOOLEAN;}
array       {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_ARRAY;}
function    {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_FUNCTION;}
if          {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_IF;}
else        {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_ELSE;}
while       {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_WHILE;}
scanf       {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_SCANF;}
printf      {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_PRINTF;}
return      {col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_RETURN;}

";"          {col+=yyleng; fprintf(fout, ";D:\t;\n"); return TOK_PUNTOYCOMA;}
","          {col+=yyleng; fprintf(fout, ";D:\t,\n"); return TOK_COMA;}
"("          {col+=yyleng; fprintf(fout, ";D:\t(\n"); return TOK_PARENTESISIZQUIERDO;}
")"          {col+=yyleng; fprintf(fout, ";D:\t)\n"); return TOK_PARENTESISDERECHO;}
"["          {col+=yyleng; fprintf(fout, ";D:\t[\n"); return TOK_CORCHETEIZQUIERDO;}
"]"          {col+=yyleng; fprintf(fout, ";D:\t]\n"); return TOK_CORCHETEDERECHO;}
"{"          {col+=yyleng; fprintf(fout, ";D:\t{\n"); return TOK_LLAVEIZQUIERDA;}
"}"          {col+=yyleng; fprintf(fout, ";D:\t}\n"); return TOK_LLAVEDERECHA;}
"="          {col+=yyleng; fprintf(fout, ";D:\t=\n"); return TOK_ASIGNACION;}
"+"          {col+=yyleng; fprintf(fout, ";D:\t+\n"); return TOK_MAS;}
"-"          {col+=yyleng; fprintf(fout, ";D:\t-\n"); return TOK_MENOS;}
"/"          {col+=yyleng; fprintf(fout, ";D:\t/\n"); return TOK_DIVISION;}
"*"          {col+=yyleng; fprintf(fout, ";D:\t*\n"); return TOK_ASTERISCO;}
"&"          {col+=yyleng; fprintf(fout, ";D:\t&\n"); return TOK_AND;}
"|"          {col+=yyleng; fprintf(fout, ";D:\t|\n"); return TOK_OR;}
"!"          {col+=yyleng; fprintf(fout, ";D:\t!\n"); return TOK_NOT;}
"=="         {col+=yyleng; fprintf(fout, ";D:\t==\n"); return TOK_IGUAL;}
"!="         {col+=yyleng; fprintf(fout, ";D:\t!=\n"); return TOK_DISTINTO;}
"<="         {col+=yyleng; fprintf(fout, ";D:\t<=\n"); return TOK_MENORIGUAL;}
">="         {col+=yyleng; fprintf(fout, ";D:\t>=\n"); return TOK_MAYORIGUAL;}
"<"          {col+=yyleng; fprintf(fout, ";D:\t<\n"); return TOK_MENOR;}
">"          {col+=yyleng; fprintf(fout, ";D:\t>\n"); return TOK_MAYOR;}
[ \t\r]				{col += yyleng;}
{ENTERO}			{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_CONSTANTE_ENTERA;}
{COMENTARIO}|"\n"	{col = 0; line++;}
{IDENTIFICADOR}		{
						if (yyleng > 50) {
							fprintf(stdout, "ERROR MORFOLOGICO:%d:%d:IDENTIFICADOR DEMASIADO LARGO (%s)\n", line, col, yytext);
							return TOK_ERROR;
						} else {
							col += yyleng;
							fprintf(fout, ";D:\t%s\n", yytext);
							return TOK_IDENTIFICADOR;
						}
					}
.					{col+=yyleng;
						fprintf(stdout, "ERROR MORFOLOGICO:%d:%d:CARACTER INVALIDO (%s)\n", line, col, yytext);
						return TOK_ERROR;}
%%
