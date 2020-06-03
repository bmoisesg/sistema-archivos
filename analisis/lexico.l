%option case-insensitive
%option yylineno

%{

#include <cstdlib>
#include "parser.h"
#include <stdio.h>
#include <iostream>

int yylex();
void yyerror(const char *s);
int line=0;
int column = 0;
int previous = 0;
%}


%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput


rMkdisk     "mkdisk"
rSize       "size"
rFit        "fit"
rUnit       "unit"
rPath       "path"
rRmdisk     "rmdisk"
rFdisck     "fdisk"
rType       "type"
rDelete     "delete"
rName       "name"
rAdd        "add"
rMount      "mount"
rRep        "rep"
rId         "id"
rUnmount    "unmount"
rExec       "exec"



rMkfs   "mkfs"
rFs     "fs"
rLogin  "login"
rUsr    "usr"
rPwd    "pwd"
rLogout "logout"
rMkgrp  "mkgrp"
rRmgrp  "rmgrp"
rMkusr  "mkusr"
rGrp    "grp"
rRmusr  "rmusr"
rChmod  "chmod"
rUgo    "ugo"
rPause  "pause"
rMkfile "mkfile"
r2fs    "2fs"
r3fs    "3fs"
rRuta   "ruta"
rCont   "cont"
rCat    "cat"
rFile   "file"
rRem    "rem"
rEdit   "edit"
rRen    "ren"
rMkdir  "mkdir"
rCp     "cp"
rDest   "dest"
rMv     "mv"
rFind   "find"
rChown  "chown"
rChgrp  "chgrp"



punto "."

er_number   [0-9]+
er_id       [a-z][a-zA-Z_0-9]*
er_cadena   "\""[^"\""]*"\""
er_path     ("/"[a-zA-Z0-9]+)+("."[a-zA-Z]+)?
%x CADENA COM

%%
<INITIAL>
{


"#"         { BEGIN COM;}
{rRuta}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rRuta;}
{r2fs}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return r2fs;}
{r3fs}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return r3fs;}
{rMkdisk}   {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rMkdisk;}
{rSize}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rSize;}
{rFit}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rFit;}
{rUnit}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rUnit;}
{rPath}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rPath;}
{rRmdisk}   {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rRmdisk;}
{rFdisck}   {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rFdisck;}
{rType}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rType;}
{rDelete}   {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rDelete;}
{rName}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rName;}
{rAdd}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rAdd;}
{rMount}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rMount;}
{rRep}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rRep;}
{rId}       {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rId;}
{rUnmount}  {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rUnmount;}
{rExec}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rExec;}
{rPause}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rPause;}
{rMkfs}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rMkfs;}
{rFs}       {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rFs;}
{rLogin}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rLogin;}
{rUsr}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rUsr;}
{rPwd}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rPwd;}
{rLogout}   {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rLogout;}
{rMkgrp}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rMkgrp;}
{rRmgrp}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rRmgrp;}
{rMkusr}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rMkusr;}
{rGrp}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rGrp;}
{rRmusr}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rRmusr;}
{rChmod}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rChmod;}
{rUgo}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rUgo;}
{rMkfile}   {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rMkfile;}

{rCont}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rCont;}
{rCat}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rCat;}
{rFile}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rFile;}
{rRem}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rRem;}
{rEdit}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rEdit ;}
{rRen}      {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rRen;}
{rMkdir}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rMkdir;}
{rCp}       {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rCp;}
{rDest}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rDest;}
{rMv}       {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rMv;}
{rFind}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rFind ;}
{rChown}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rChown ;}
{rChgrp}    {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return rChgrp;}
{punto}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return punto;}

{er_number} {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return er_number;}
{er_id}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return er_id;}
{er_cadena} {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return er_cadena;}
{er_path}   {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return er_path;}


"-"         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return guion;}
"="         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return igual;}

"\t"                {strcpy(yylval.TEXT, yytext); column=26;}
[[:blank:]]         {column++;}
"\n"                {line++; column=0; previous=0;}
.                   { }
}

<COM>
{
"\n"                {line++; column = 0; BEGIN INITIAL;}
.                   { }
}

%%
