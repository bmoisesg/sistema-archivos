#exec -path=/home/bmoi6/Desktop/entrada.sh
#CREANDO DISCOS ----------------------------------------------------------------------------------------
mkdisk -size=50 -unit=M -path=/home/bmoi6/archivos/fase1/Disco1.disk -fit=BF
mkdisk -size=15 -unit=M -path=/home/bmoi6/archivos/fase1/Disco7.disk -fit=BF
mkdisk -unit=K -size=51200 -path=/home/bmoi6/archivos/fase1/Disco2.disk -fit=BF
mkDisk -size=10 -path=/home/bmoi6/archivos/fase1/Disco4.disk -unit=k -fit=BF
mkdisk -size=51200 -unit=k -path="/home/bmoi6/archivos/fase1/mis archivos/Disco3.disk" -fit=BF
mkdisk -size=51200 -Unit=k -path="/home/bmoi6/archivos/fase1/mis archivos/archivos/Disco5.disk" -fit=BF

#ELIMINANDO DISCOS ------------------------------------------------------------------------------------
#Elimina un D, el primero debería dar error
#rmDisk -path=/home/bmoi6/archivos/fase1/Disco4.disk
#rmDisk -path=/home/bmoi6/archivos/fase1/Disco2.disk
#rmDisk -path="/home/bmoi6/archivos/fase1/mis archivos/Disco3.disk"

#CREANDO PARTICIONES ----------------------------------------------------------------------------------
#Crear particiones Disco1.disk
fdisk -type=P -unit=K -name=Part1 -size=7680 -path=/home/bmoi6/archivos/fase1/Disco1.disk -fit=BF
fdisk -type=E -unit=K -name=Part2 -size=7680 -path=/home/bmoi6/archivos/fase1/Disco1.disk -fit=FF
fdisk -type=E -unit=K -name=Part3 -size=7680 -path=/home/bmoi6/archivos/fase1/Disco1.disk -fit=WF #Debe dar error por que ya existe una extendida
fdisk -type=P -unit=K -name=Part3 -size=7680 -path=/home/bmoi6/archivos/fase1/Disco1.disk -fit=WF
fdisk -type=P -unit=K -name=Part4 -size=7680 -path=/home/bmoi6/archivos/fase1/Disco1.disk -fit=BF

#Crear particiones Disco2.disk
fdisk -type=P -unit=K -name=Part12 -size=4680 -path=/home/bmoi6/archivos/fase1/Disco2.disk -fit=BF
fdisk -type=P -unit=K -name=Part13 -size=4680 -path=/home/bmoi6/archivos/fase1/Disco2.disk -fit=WF
fdisk -type=P -unit=K -name=Part14 -size=4680 -path=/home/bmoi6/archivos/fase1/Disco2.disk -fit=BF
fdisk -type=E -unit=K -name=Part15 -size=17360 -path=/home/bmoi6/archivos/fase1/Disco2.disk -fit=WF

#MONTAR ----------------------------------------------------------------------------------
#Monta las particiones Disco1.disk
mount -path=/home/bmoi6/archivos/fase1/Disco1.disk -name=Part1 #vda1
mount -path=/home/bmoi6/archivos/fase1/Disco1.disk -name=Part2 #vda2 extendida
mount -path=/home/bmoi6/archivos/fase1/Disco1.disk -name=Part3 #vda3
mount -path=/home/bmoi6/archivos/fase1/Disco2.disk -name=Part12 #vdb1
mount -path=/home/bmoi6/archivos/fase1/Disco2.disk -name=Part13 #vdb2
mount -path=/home/bmoi6/archivos/fase1/Disco2.disk -name=Part14 #vdb3
mount -path=/home/bmoi6/archivos/fase1/Disco2.disk -name=Part15 #vdb4


#Desmontar las particiones
unmount -id=vdb4
#Desmontar Error
unmount -id=vdx1


#Creando reportes
rep -id=vda1 -Path=/home/bmoi6/entrada/mbr1.png -name=mbr 
rep -id=vda1 -Path=/home/bmoi6/entrada/disk1.png -name=disk
rep -id=vdb1 -Path=/home/bmoi6/entrada/mbr4.png -name=mbr 
rep -id=vdb1 -Path=/home/bmoi6/entrada/disk4.png -name=disk

#Eliminando particiones
fdisk -delete=fast -name=Part1 -path=/home/bmoi6/archivos/fase1/Disco1.disk
fdisk -delete=fast -name=Part6 -path=/home/bmoi6/archivos/fase1/Disco1.disk   #error
fdisk -delete=fast -name=Part11 -path=/home/bmoi6/archivos/fase1/Disco2.disk  #error
fdisk -delete=fast -name=Part13 -path=/home/bmoi6/archivos/fase1/Disco2.disk   

#Creando reportes
rep -id=vda1 -Path=/home/bmoi6/entrada/mbr2.png -name=mbr 
rep -id=vda1 -Path=/home/bmoi6/entrada/disk2.png -name=disk
rep -id=vda2 -Path=/home/bmoi6/entrada/mbr2.png -name=mbr 
rep -id=vda2 -Path=/home/bmoi6/entrada/disk2.png -name=disk
rep -id=vdb1 -Path=/home/bmoi6/entrada/mbr5.png -name=mbr 
rep -id=vdb1 -Path=/home/bmoi6/entrada/disk5.png -name=disk