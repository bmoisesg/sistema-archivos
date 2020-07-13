#include "rep.h"

rep::rep(lista_parametros entrando)
{
    this->parametros= entrando.list_parametro;
}
void rep::ejecutar(){
    imprimir("\t->rep");
    if(!revisarExitanParametros({"name","path","id"})) return;
    if(!si_es_tiene_que_tener("name",{"mbr","disk"})) return;
    this->id=getParametro("id");
    this->name=getParametro("name");
    this->path=getParametro("path");

    MBR elMBR=getMBR(id);

    QString reporte_encabezado="digraph g {node [shape=plaintext];disco [label=<<TABLE BORDER=\"1\" CELLPADDING='15'>";
    QString reporte_final="</TABLE>>];}";

    if(name=="disk"){
        QString reporte_contenido="<td>MBR<br/>"+QString::number((sizeof (MBR)*1.0)/elMBR.mbr_tam*100)+"%</td>";

        listaParticiones_tmp=getPartionesOrdenaas(elMBR);

        ///el vector listaparticiones_tmp ya esta ordenado de forma ascendete con respecto al atributo "start" de la particion
        for(int x=0;x<listaParticiones_tmp.size()-1;x++){

            int siguiente_particion=listaParticiones_tmp.at(x).part_start+listaParticiones_tmp.at(x).part_size;
            QString tipo;
            if(listaParticiones_tmp.at(x).part_type=='p')tipo="primaria";
            if(listaParticiones_tmp.at(x).part_type=='e')tipo="extendida";

            reporte_contenido= reporte_contenido+"<td><u><i>"+tipo+"</i></u><br/>"
                    +"<b>"+listaParticiones_tmp.at(x).part_name+"</b><br/>"
                    //+QString::number(listaParticiones_tmp.at(x).part_start)+"<br/>"
                    +QString::number(((listaParticiones_tmp.at(x).part_size*1.0)/elMBR.mbr_tam*1.0)*100)+"%"
                    +"</td>";
            if(listaParticiones_tmp.at(x+1).part_start!=siguiente_particion){
                reporte_contenido= reporte_contenido+"<td>  libre <br/>"
                        +QString::number(((listaParticiones_tmp.at(x+1).part_start-siguiente_particion*1.0)/(elMBR.mbr_tam*1.0))*100)+"%  </td>";
            }
        }
        ofstream file;
        file.open("grafica_rep.dot");
        file << reporte_encabezado.toUtf8().constData()<<"<tr>";
        file << reporte_contenido.toUtf8().constData()<<"</tr>";
        file << reporte_final.toUtf8().constData();
        file.close();

    }else if(name=="mbr"){
        ofstream file;
        file.open("grafica_rep.dot");
        file << reporte_encabezado.toUtf8().constData();

        QString reporte_contenido="<tr><td>Atributo</td><td>valor</td></tr>";
        reporte_contenido+="<tr><td>tamanio</td><td>"+QString::number(elMBR.mbr_tam)+"</td></tr>";
        reporte_contenido+="<tr><td>fecha creacion</td><td>";
        file << reporte_contenido.toUtf8().constData();
        file << elMBR.mbr_fecha_creacion<<"</td></tr><tr><td>asignatura</td><td>" << elMBR.mbr_disk_signatura<<"</td></tr><tr><td>fit</td><td>"<<elMBR.mbr_disk_fit<<"</td></tr>";
        if(elMBR.mbr_partition1.part_status=='1') file << "<tr><td>"<<elMBR.mbr_partition1.part_name<<"</td><td><table><tr><td>type</td><td>"<<elMBR.mbr_partition1.part_type<<"</td></tr><tr><td>fit</td><td>"<<elMBR.mbr_partition1.part_fit<<"</td></tr><tr><td>start</td><td>"<<elMBR.mbr_partition1.part_start<<"</td></tr><tr><td>size</td><td>"<<elMBR.mbr_partition1.part_size<<"</td></tr></table></td></tr>";
        if(elMBR.mbr_partition2.part_status=='1') file << "<tr><td>"<<elMBR.mbr_partition2.part_name<<"</td><td><table><tr><td>type</td><td>"<<elMBR.mbr_partition2.part_type<<"</td></tr><tr><td>fit</td><td>"<<elMBR.mbr_partition2.part_fit<<"</td></tr><tr><td>start</td><td>"<<elMBR.mbr_partition2.part_start<<"</td></tr><tr><td>size</td><td>"<<elMBR.mbr_partition2.part_size<<"</td></tr></table></td></tr>";
        if(elMBR.mbr_partition3.part_status=='1') file << "<tr><td>"<<elMBR.mbr_partition3.part_name<<"</td><td><table><tr><td>type</td><td>"<<elMBR.mbr_partition3.part_type<<"</td></tr><tr><td>fit</td><td>"<<elMBR.mbr_partition3.part_fit<<"</td></tr><tr><td>start</td><td>"<<elMBR.mbr_partition3.part_start<<"</td></tr><tr><td>size</td><td>"<<elMBR.mbr_partition3.part_size<<"</td></tr></table></td></tr>";
        if(elMBR.mbr_partition4.part_status=='1') file << "<tr><td>"<<elMBR.mbr_partition4.part_name<<"</td><td><table><tr><td>type</td><td>"<<elMBR.mbr_partition4.part_type<<"</td></tr><tr><td>fit</td><td>"<<elMBR.mbr_partition4.part_fit<<"</td></tr><tr><td>start</td><td>"<<elMBR.mbr_partition4.part_start<<"</td></tr><tr><td>size</td><td>"<<elMBR.mbr_partition4.part_size<<"</td></tr></table></td></tr>";

        file << reporte_final.toUtf8().constData()<<"";
        file.close();
    }

    ejecutar_comando("dot -Tpng grafica_rep.dot -o "+path);
    ejecutar_comando("shotwell "+path);
    imprimir("[REP] terminado");
}
