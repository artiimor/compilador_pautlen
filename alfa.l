%{
#include <stdlib.h>
#include <stdio.h>

#include "alfa.h"
#include "tablahash.h"
#include "generacion.h"

#include "y.tab.h"

int line = 1;
int col = 0;
extern FILE* fout;

%}

%option noyywrap

DIGITO			[0-9]
LETRA			[a-zA-Z]
ENTERO			{DIGITO}*
COMENTARIO		"//".*\n
IDENTIFICADOR 	{LETRA}({LETRA}|{DIGITO})*

%%
function			{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_FUNCTION;}
return				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_RETURN;}
main				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_MAIN;}
boolean				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_BOOLEANO;}
array				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_ARRAY;}
printf				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_PRINTF;}
int					{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_INT;}
if					{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_IF;}
else				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_ELSE;}
while				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_WHILE;}
scanf				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_SCANF;}
false				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_FALSE;}
true				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_TRUE;}
==					{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_IGUAL;}
"!="				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_DISTINTO;}
"<="				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_MENORIGUAL;}
">="				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_MAYORIGUAL;}
"&&"				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_AND;}
"||"				{col+=yyleng; fprintf(fout, ";D:\t%s\n", yytext); return TOK_OR;}
";"					{col+=yyleng; fprintf(fout, ";D:\t;\n"); return yytext[0];}
"#"					{col+=yyleng; fprintf(fout, ";D:\t#\n"); return yytext[0];}
","					{col+=yyleng; fprintf(fout, ";D:\t,\n"); return yytext[0];}
"="					{col+=yyleng; fprintf(fout, ";D:\t=\n"); return yytext[0];}
"("					{col+=yyleng; fprintf(fout, ";D:\t(\n"); return yytext[0];}
")"					{col+=yyleng; fprintf(fout, ";D:\t)\n"); return yytext[0];}
"{"					{col+=yyleng; fprintf(fout, ";D:\t{\n"); return yytext[0];}
"}"					{col+=yyleng; fprintf(fout, ";D:\t}\n"); return yytext[0];}
"["					{col+=yyleng; fprintf(fout, ";D:\t[\n"); return yytext[0];}
"]"					{col+=yyleng; fprintf(fout, ";D:\t]\n"); return yytext[0];}
":"					{col+=yyleng; fprintf(fout, ";D:\t:\n"); return yytext[0];}
"+"					{col+=yyleng; fprintf(fout, ";D:\t+\n"); return yytext[0];}
"-"					{col+=yyleng; fprintf(fout, ";D:\t-\n"); return yytext[0];}
"/"					{col+=yyleng; fprintf(fout, ";D:\t/\n"); return yytext[0];}
"*"					{col+=yyleng; fprintf(fout, ";D:\t*\n"); return yytext[0];}
">"					{col+=yyleng; fprintf(fout, ";D:\t>\n"); return yytext[0];}
"<"					{col+=yyleng; fprintf(fout, ";D:\t<\n"); return yytext[0];}
"&"					{col+=yyleng; fprintf(fout, ";D:\t&\n"); return yytext[0];}
"!"					{col+=yyleng; fprintf(fout, ";D:\t!\n"); return yytext[0];}
"."					{col+=yyleng; fprintf(fout, ";D:\t.\n"); return yytext[0];}
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
						fprintf(stdout, "****Error en [lin %d, col %d]: simbolo no permitido (%s)\n", line, col, yytext);
						return TOK_ERROR;}


%%
