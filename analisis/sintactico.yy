%{
    #include <iostream>
    #include "scanner.h"
    #include "parametro.h"
    #include "instruccion.h"
    #include "lista_comandos.h"
    #include "lista_parametros.h"


    #include "comando/exec.h"
    #include "comando/fdisk.h"
    #include "comando/mkdisk.h"
    #include "comando/mount.h"
    #include "comando/rep.h"
    #include "comando/rmdisk.h"
    #include "comando/unmount.h"

    extern int yylineno;
    extern int column;
    extern char *yytext;
    extern lista_comandos *raiz= new lista_comandos(); //raiz

    // lista_comando* getRoot(void*);

    int yyerror(const char* mens)
    {
        yylineno++;
        column++;
        std::cout <<"\tERROR SINTACTICO:"<< mens <<"\n\tlexema: "<<yytext<<"\n\tlin   :"<<yylineno<<"\n\tcol   :"<<column<<std::endl;
        return 0;
    }


%}

%defines "parser.h"
%output "parser.cpp"
%define parse.error verbose
%locations

%union{
  char TEXT [256]="";
  class instruccion * Instruccion;
  class lista_comandos *Lista_comandos;
  class lista_parametros * Lista_parametros;
  class parametro *Parametro;
//   class exec *Exec;
//   class fdisk *Fdisk;
//   class mkdisk *Mkdisk;
//   class mount *Mount;
//   class repdisk *Repdisk;
//   class repmbr *Repmbr;
//   class rmdisk *Rmdisk;
//   class unmount *Unmount;
}

//Terminales
%token<TEXT> rMkdisk;
%token<TEXT> rSize;
%token<TEXT> rFit;
%token<TEXT> rUnit;
%token<TEXT> rPath;
%token<TEXT> rRmdisk;
%token<TEXT> rFdisck;
%token<TEXT> rType;
%token<TEXT> rDelete;
%token<TEXT> rName;
%token<TEXT> rAdd;
%token<TEXT> rMount;
%token<TEXT> rRep;
%token<TEXT> rId;
%token<TEXT> rUnmount;
%token<TEXT> rExec;
%token<TEXT> punto;
%token<TEXT> er_number;
%token<TEXT> er_id;
%token<TEXT> er_cadena;
%token<TEXT> er_path;
%token<TEXT> guion;
%token<TEXT> igual;
%token<TEXT> rMkfs;
%token<TEXT> rFs ;
%token<TEXT> rLogin ;
%token<TEXT> rUsr ;
%token<TEXT> rPwd ;
%token<TEXT> rLogout ;
%token<TEXT> rMkgrp ;
%token<TEXT> rRmgrp ;
%token<TEXT> rMkusr ;
%token<TEXT> rGrp ;
%token<TEXT> rRmusr ;
%token<TEXT> rChmod ;
%token<TEXT> rUgo ;
%token<TEXT> rMkfile ;
%token<TEXT> r2fs ;
%token<TEXT> r3fs ;
%token<TEXT> rCont ;
%token<TEXT> rCat ;
%token<TEXT> rFile ;
%token<TEXT> rRem ;
%token<TEXT> rEdit ;
%token<TEXT> rPause ;
%token<TEXT> rRen ;
%token<TEXT> rMkdir ;
%token<TEXT> rCp;
%token<TEXT> rDest;
%token<TEXT> rMv;
%token<TEXT> rRuta;
%token<TEXT> rFind;
%token<TEXT> rChown;
%token<TEXT> rChgrp;

//No Terminales
%type<Lista_parametros> LISTA_PARAMETRO
%type<Lista_comandos> LISTA_COMANDOS;
%type<Instruccion>COMANDO;
%type<Parametro> PARAMETRO;
%type<TEXT> TITULOPARAMETRO;
%type<TEXT> VALORPARAMETRO;

%start INICIO
%%
INICIO:   LISTA_COMANDOS {  raiz = $1;   }
;
LISTA_COMANDOS: LISTA_COMANDOS COMANDO
        {
            $$= $1;
            $$->add($2);
        }
        |COMANDO
        {
            $$= new lista_comandos();
            $$->add($1);
        }
;

LISTA_PARAMETRO: LISTA_PARAMETRO PARAMETRO
        {
            $$=$1;
            $$->agregar(*$2);
        }
        |PARAMETRO
        {
            $$= new lista_parametros();
            $$->agregar(*$1);

        }
;
PARAMETRO: guion TITULOPARAMETRO igual VALORPARAMETRO
        {
            $$= new parametro($2,$4);
        }
        |
        guion TITULOPARAMETRO igual er_number
        {
            $$= new parametro($2,atoi($4));
        }
;

VALORPARAMETRO:
     er_id      
    |er_path    
    |er_cadena      
;
TITULOPARAMETRO:
             rSize      
            |rUnit      
            |rFit       
            |rPath      
            |rName      
            |rId        
            |rType      
            |rDelete    
            |rAdd       
            |rRuta      
            |rFs        
            |rUsr       
            |rPwd       
            |rGrp       
            |rUgo       
            |rCont      
            |rFile      
            |rDest      
;
 
COMANDO:
        rMkdisk   LISTA_PARAMETRO {$$= new mkdisk(*$2);}
        |rRmdisk  LISTA_PARAMETRO {$$= new rmdisk(*$2);}
        |rFdisck  LISTA_PARAMETRO {$$= new fdisk(*$2);}
        |rMount   LISTA_PARAMETRO {$$= new mount(*$2);}
        |rUnmount LISTA_PARAMETRO {$$= new unmount(*$2);}
        |rExec    LISTA_PARAMETRO {$$= new exec(*$2);}
        |rRep     LISTA_PARAMETRO {$$= new rep(*$2);}


%%
