#include "instruccion.h"

void instruccion::imprimir(QString contenido)
{
    cout<<contenido.toUtf8().constData()<<endl;
}
bool instruccion::revisarExitanParametros(QStringList lista)
{
    //lista contiene los parametros obligatorios de la instruccion

    for (QString x:lista)
    {
        if(!revisarParametro(x))
        {
            imprimir("ERROR, no se ingreso el parametro <"+x+">");
            return  false;
        }
    }
    return true;

}
bool instruccion::revisarParametro(QString name)
{

    for(parametro x :parametros)
    {
        if(x.nombre==name)return true;
    }
    return false;
}
QString instruccion::getParametro(QString nombre)
{

    for(parametro x :parametros)
    {
        if(x.nombre==nombre)return x.valor;
    }
    return "@error";
}

int instruccion::getParametro_int(QString nombre)
{

    for(parametro x :parametros)
    {
        if(x.nombre==nombre)return x.numero;
    }
    return -1;
}

bool instruccion::si_es_tiene_que_tener(QString nombre, QList<QString> lista){

    QString valor= getParametro(nombre);
    bool flag=false;
    for(QString x:lista){
        if(valor==x)flag=true;
    }
    if(flag) return true;
    imprimirErrorParametro("<"+nombre+"> con valor <"+valor+">");
    return false;
}

void instruccion::imprimirErrorParametro(QString contenido){
        imprimir("ERROR, parametro "+contenido+" no valido");
}

void instruccion::crearCarpetas(QString name){
    QStringList lista = name.split("/");
    QString guardar="mkdir -p \"/";
    for(int x=0; x<lista.length()-1;x++){
        guardar=guardar+lista.at(x)+"/";
    }
    guardar=guardar+"\"";
    system(guardar.toUtf8().constData());
}
int instruccion::getTamReal(int num, QString letra){
    if(letra=="k")       return num*1024;
    else if (letra=="m") return num*1024*1024;
    else if (letra=="b") return num;
    return 0;
}
bool instruccion::pregunta_seguridad_para_eliminar(){
    while(true){
        cout<<"\tseguro que queiere eliminar?[S/N]";
        int num=getchar();
        cin.ignore();
        if(num==83|| num==115){//s
            return true;
        }else if(num==78|| num==110){//n
            return false;
        }
    }
}
MBR instruccion::getMBR(QString ruta){
    //traer el mbr que esta escrito en el disco
    MBR elMBR;
    ifstream archivo(ruta.toUtf8());
    if(archivo.is_open())
    {
        archivo.seekg(0,ios::beg);
        archivo.read(reinterpret_cast<char*>(&elMBR),sizeof(MBR));
        archivo.close();
    }else
    {
        imprimir("error, <path> no valida");
        return elMBR;
    }
    return elMBR;
}
void instruccion::ejecutar_comando(QString contenido){

    system(contenido.toUtf8().constData());
}
vector<PARTITION> instruccion::getPartionesOrdenaas(MBR elMBR){

    vector <PARTITION> listaParticiones_tmp;
    if (elMBR.mbr_partition1.part_status=='1')listaParticiones_tmp.push_back(elMBR.mbr_partition1);
    if (elMBR.mbr_partition2.part_status=='1')listaParticiones_tmp.push_back(elMBR.mbr_partition2);
    if (elMBR.mbr_partition3.part_status=='1')listaParticiones_tmp.push_back(elMBR.mbr_partition3);
    if (elMBR.mbr_partition4.part_status=='1')listaParticiones_tmp.push_back(elMBR.mbr_partition4);

    if(listaParticiones_tmp.size()>1){
        while (true) {
            bool flag=true;
            for(int x=0; x<listaParticiones_tmp.size()-1;x++){
                if(listaParticiones_tmp.at(x).part_start>listaParticiones_tmp.at(x+1).part_start){
                    PARTITION tmp= listaParticiones_tmp.at(x);
                    listaParticiones_tmp.at(x)=listaParticiones_tmp.at(x+1);
                    listaParticiones_tmp.at(x+1)=tmp;
                }
            }
            for(int x=0; x<listaParticiones_tmp.size()-1;x++){
                if(listaParticiones_tmp.at(x).part_start>listaParticiones_tmp.at(x+1).part_start)flag=false;
            }
            if(flag)break;
        }
    }
    PARTITION nuevo;
    nuevo.part_start=elMBR.mbr_tam;
    listaParticiones_tmp.push_back(nuevo);
    return listaParticiones_tmp;
}
