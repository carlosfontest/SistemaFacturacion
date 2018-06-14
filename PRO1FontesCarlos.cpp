/* FACTURADORA COMPA�IA DE ENVIOS EXPRESS C.A 
   Programador: Carlos Fontes - 20171110221
   Profesor: Nicolas Araque.
   Preparador: Alejandro Macari.
   PROYECTO N� 1 - Algoritmos y Programaci�n. */
   

#include<math.h>                   //Librer�a que usar� para redondear numeros  (ceil)
#include<iomanip>                  //Librer�a que usar� para hacer precisiones de decimales con setprecision
#include<locale.h>                 //Librer�a para poder poner "�" y acentos
#include<conio.h>                  //Librer�a para poder usar el getch (pausa del sistema)
#include<iostream>                 //Librer�a principal de entrada y salida de datos
using namespace std;


 //FUNCIONES -->



 //FUNCI�N PARA LA IMPRESI�N DE LA FACTURA AL FINAL DEL D�A (VOID)(PAR�METROS)
 void ImpresionFacturaFinal(int contFacturas, int contDocumentos, int contPaquetes, float pesoMax, float pesoVolMin, float acumMontoPaquetes, float acumMontoDocumentos, float pesoVolumetricoPaquete, int cedulaMax, int cedulaVolMin, float montoMax, float montoVolMin, float acumIVA, char tipoEncomienda, float pesoEncomiendaVolMin){
   cout<<fixed;
	cout<<"\n\t\t\t\t            Gracias por usar nuestro software. \n\t\t\t\t    Se proceder� a mostrar los datos de todo el d�a."<<endl;
	cout<<"\n\n\n\t\t\t    ================================================================";
	cout<<"\n\t\t\t     � CANTIDAD DE FACTURAS EMITIDAS:                 "<<contFacturas;
	cout<<"\n\t\t\t     � CANTIDAD DE ENV�OS DE DOCUMENTOS:              "<<contDocumentos;
	cout<<"\n\t\t\t     � CANTIDAD DE ENV�OS DE PAQUETES:                "<<contPaquetes;
	
	if(contPaquetes > 0){
	cout<<"\n\n\t\t\t     � PAQUETE M�S PESADO:                            "<<setprecision(2)<<pesoMax<<"\n\t\t\t         -C�DULA:                                     "<<cedulaMax<<"\n\t\t\t         -MONTO QUE PAG�:                             "<<setprecision(2)<<montoMax;}
	else{
	cout<<"\n\n\t\t\t     � PAQUETE M�S PESADO:                            --No Aplica--"<<"\n\t\t\t         -C�DULA:                                     --No Aplica--"<<"\n\t\t\t         -MONTO QUE PAG�:                             --No Aplica--";    }
	
	
	if(contPaquetes > 0){
	cout<<"\n\n\t\t\t     � PAQUETE MENOS PESO VOLUM�TRICO:                "<<setprecision(3)<<pesoVolMin<<"\n\t\t\t         -C�DULA:                                     "<<cedulaVolMin<<"\n\t\t\t         -MONTO QUE PAG�:                             "<<setprecision(2)<<montoVolMin<<"\n\t\t\t         -PESO DE SU ENCOMIENDA:                      "<<setprecision(2)<<pesoEncomiendaVolMin;}
	else{
	cout<<"\n\t\t\t     � PAQUETE MENOS PESO VOLUM�TRICO:                --No Aplica--"<<"\n\t\t\t         -C�DULA:                                     --No Aplica--"<<"\n\t\t\t         -MONTO QUE PAG�:                             --No Aplica--"<<"\n\t\t\t         -PESO DE SU ENCOMIENDA:                      --No Aplica--";}
	
	cout<<"\n\n\t\t\t     � MONTO TOTAL NETO FACTURADO:                    "<<setprecision(2)<< (acumMontoPaquetes + acumMontoDocumentos);
	cout<<"\n\t\t\t     � MONTO TOTAL IVA COBRADO:                       "<<setprecision(2)<<acumIVA;
	
	if(acumMontoDocumentos != 0){
	cout<<"\n\t\t\t     � PROMEDIO DE PAGO CLIENTES DOCUMENTOS:          "<<setprecision(2)<< (acumMontoDocumentos/contDocumentos);}
	else{
	cout<<"\n\t\t\t     � PROMEDIO DE PAGO CLIENTES DOCUMENTOS:          --No Aplica--";}
	
	if(acumMontoPaquetes != 0){
	cout<<"\n\t\t\t     � PROMEDIO DE PAGO CLIENTES PAQUETES:            "<<setprecision(2)<< (acumMontoPaquetes/contPaquetes);}
	else{
	cout<<"\n\t\t\t     � PROMEDIO DE PAGO CLIENTES PAQUETES:            --No Aplica--";}
		
	cout<<"\n\t\t\t    ================================================================";
	cout<<"\n\n\n\t\t\t\t\t\t     HASTA LUEGO.";
}



 //FUNCI�N PARA CALCULAR LOS M�NIMOS QUE PIDEN (VOID)(PAR�METROS Y REFERENCIA)
 void CalculoDeMinimos(float pesoVolumetricoPaquete, int cedula, float precioTotal, float &pesoVolMin, int &cedulaVolMin, float &montoVolMin, char tipoEncomienda, float pesoEncomienda, float &pesoEncomiendaVolMin){
 	 if(tipoEncomienda == 'p' || tipoEncomienda == 'P'){	
 	  if(pesoVolumetricoPaquete < pesoVolMin || pesoVolMin == -1){
	  pesoVolMin = pesoVolumetricoPaquete;
	  cedulaVolMin = cedula;
	  montoVolMin = precioTotal;
	  pesoEncomiendaVolMin = pesoEncomienda;
     }
    }
 }



 //FUNCI�N PARA CALCULAR LOS M�XIMOS QUE PIDEN (VOID)(PAR�METROS Y REFERENCIA)
 void CalculoDeMaximos(float pesoEncomienda, int cedula, float precioTotal, float &pesoMax, int &cedulaMax, float &montoMax, char tipoEncomienda){
 	if(tipoEncomienda == 'P' || tipoEncomienda == 'p'){
	 if(pesoEncomienda > pesoMax || pesoMax == -1){
	  pesoMax = pesoEncomienda;
	  cedulaMax = cedula;
	  montoMax = precioTotal;
	}	
 }
}



 //FUNCI�N PARA IMPRESI�N DE LA GUIA POR CADA ENCOMIENDA (VOID)(PARAMETROS)
 void ImpresionGuia(int cedula, float pesoEncomienda, char tipoEncomienda, float pesoVolumetricoPaquete, char medioPago, float precioSinIVA, float IVA, float precioTotal, int auxIVA){
  cout<<fixed; 	 
  cout<<"\n\t\t\t              LOS DATOS DE SU ENCOMIENDA SON:";	
  cout<<"\n\t\t\t    ===================================================";
  cout<<"\n\t\t\t     � C�DULA:                            "<<cedula;
  cout<<"\n\t\t\t     � PESO DE LA ENCOMIENDA:             "<<setprecision(2)<<pesoEncomienda;
  
  if(tipoEncomienda == 'd' || tipoEncomienda == 'D'){
    cout<<"\n\t\t\t     � TIPO DE ENCOMIENDA:                "<<"Documento";}
  else{
    cout<<"\n\t\t\t     � TIPO DE ENCOMIENDA:                "<<"Paquete";}   
    
  if(tipoEncomienda == 'd' || tipoEncomienda == 'D'){
    cout<<"\n\t\t\t     � PESO VOLUM�TRICO:                  "<<"--No aplica--";} 
  else{
    cout<<"\n\t\t\t     � PESO VOLUM�TRICO:                  "<<setprecision(3)<<pesoVolumetricoPaquete;}  
    
  if(medioPago == 'e' || medioPago == 'E'){
    cout<<"\n\t\t\t     � M�TODO DE PAGO:                    "<<"Efectivo";}
  else{
    cout<<"\n\t\t\t     � M�TODO DE PAGO:                    "<<"Electr�nico";} 
  
 
  cout<<"\n\t\t\t     � MONTO A PAGAR (SIN IVA):           "<<setprecision(2)<<precioSinIVA; 
  cout<<"\n\t\t\t     � MONTO DEL IVA [ "<<auxIVA<<"% ]:              "<<setprecision(2)<<IVA;
  cout<<"\n\t\t\t     � MONTO TOTAL A PAGAR                "<<setprecision(2)<<precioTotal;
  cout<<"\n\t\t\t    ===================================================";	
 }



 //FUNCI�N PARA CALCULAR EL PRECIO TOTAL (NO VOID)(PARAMETROS)
 float CalculoPrecioTotal(float precioSinIVA, float IVA, char tipoEncomienda, float &acumMontoPaquetes, float &acumMontoDocumentos){
  float precioTotal = 0.0;
  
  precioTotal = precioSinIVA + IVA;
  
  if(tipoEncomienda == 'd' || tipoEncomienda == 'D'){
  	 acumMontoDocumentos = acumMontoDocumentos + precioTotal;}
  else{
    acumMontoPaquetes = acumMontoPaquetes + precioTotal; }
   
  return precioTotal;		
 }



 //FUNCI�N PARA CALCULAR EL IVA (NO VOID)(PAR�METROS)
 float CalculoIVA(char medioPago, float precioSinIVA, int &auxIVA, float &acumIVA){
  float IVA = 0.0;
  
  if(medioPago == 'e' || medioPago == 'E'){
  	 IVA = precioSinIVA * 0.12;
  	 auxIVA = 12;
  	 acumIVA = acumIVA + IVA;
  	 return IVA;}
  else{
    if(precioSinIVA <= 2000000){
    	IVA = precioSinIVA * 0.09;
    	auxIVA = 9;
    	acumIVA = acumIVA + IVA;
    	return IVA;}  
	 else{
	 	IVA = precioSinIVA * 0.07;
	 	auxIVA = 7;
	 	acumIVA = acumIVA + IVA;
	 	return IVA;}		 	
  }	
 }



 //FUNCI�N CALCULAR EL PRECIO SIN EL IVA (NO VOID)(PAR�METROS)
 float CalculoPrecioSinIVA(float pesoFinal, char tipoEncomienda){
  float precioSinIVA = 0.0, precioAdicional = 0.0;
  float cantidadMediosKilos = 0.0;
  int tarifaDoc = 62515, tarifaXDoc = 35904, tarifaPaq = 115579, tarifaXPaq = 25080;
  
  if(tipoEncomienda == 'd' || tipoEncomienda == 'D'){
  	 if(pesoFinal <= 1){
  	   	precioSinIVA = tarifaDoc;
  	   	return precioSinIVA;}
  	 else{
	   	cantidadMediosKilos = (pesoFinal-1.0)/0.5;
		   cantidadMediosKilos = ceil(cantidadMediosKilos);		   
			precioAdicional = cantidadMediosKilos * tarifaXDoc;
			precioSinIVA = precioAdicional + tarifaDoc;
			return precioSinIVA;}  	
  }
  else{
  	 if(pesoFinal <= 2){
  	   	precioSinIVA = tarifaPaq;
  	   	return precioSinIVA;}
  	 else{
	   	cantidadMediosKilos = (pesoFinal-2.0)/0.5;
		   cantidadMediosKilos = ceil(cantidadMediosKilos);		   
			precioAdicional = cantidadMediosKilos * tarifaXPaq;
			precioSinIVA = precioAdicional + tarifaPaq;
			return precioSinIVA;}  	      	
  }	
 }
 


 //FUNCI�N CALCULAR PESO FINAL (peso que se va a usar para calcular el precio) - (NO VOID)(PAR�METROS)
 float CalculoPesoFinal(char tipoEncomienda, float pesoEncomienda, float pesoVolumetricoPaquete){
  float pesoFinal = 0.0;
  
  if(tipoEncomienda == 'd' || tipoEncomienda == 'D'){
  	pesoFinal = pesoEncomienda;
  	return pesoFinal;
  }
  else if(tipoEncomienda == 'p' || tipoEncomienda == 'P'){
  	if(pesoVolumetricoPaquete >= pesoEncomienda){
  		pesoFinal = pesoVolumetricoPaquete;
  		return pesoFinal;}
	else{
	   pesoFinal = pesoEncomienda;
		return pesoFinal; }
  }
 }



 //FUNCION CALCULAR PESO VOLUMETRICO (NO VOID)(PAR�METROS)
 float CalculoPesoVolumetrico(float ancho, float alto, float profundidad){
  float pesoVolumetrico = 0.0;
  
  pesoVolumetrico = ((alto*ancho*profundidad)/5000);
   return pesoVolumetrico;	
 }



 //FUNCI�N INGRESO DE DATOS (VOID)(REFERENCIA)
 void IngresoDatos(int &cedula, char &tipoEncomienda, float &pesoEncomienda, char &medioPago, float &profundidad, float &ancho, float &altura, int &contDocumentos, int &contPaquetes){
	 	cout<<"  Ingrese su n�mero de c�dula-> ";
	 	 cin>>cedula; system("cls");	 	  
		 	 while(cedula <= 0){
			  cout<<"\a  ERROR: Ingres� una c�dula inv�lida. \n  Por favor vuelva a ingresar su c�dula -> "; cin>>cedula;
			  } system("cls");
	 	 
	 	cout<<"  Ingrese el tipo de encomienda: (D)ocumento - (P)aquete -> ";
	 	 cin>>tipoEncomienda; system("cls");
			while(tipoEncomienda != 'd' && tipoEncomienda != 'D' && tipoEncomienda != 'p' && tipoEncomienda != 'P'){
			 cout<<"\a  ERROR: Ingres� un tipo de encomienda inv�lido. \n  Por favor vuelva a ingresar el tipo de encomienda (D)ocumento - (P)aquete -> "; cin>>tipoEncomienda;
			 } system("cls");
			 
						if(tipoEncomienda == 'p' || tipoEncomienda == 'P'){
							contPaquetes++;
							cout<<"  Ingrese el ancho del paquete (cm) -> ";
							 cin>>ancho; system("cls");
						 	   while(ancho <= 0){
						 	    cout<<"\a  ERROR: Ingres� un ancho inv�lido.\n  Por favor vuelva a ingresar el ancho de su paquete (Mayor que cero) -> "; cin>>ancho;
								  } system("cls");
							
							
							cout<<"  Ingrese la altura del paquete (cm) -> ";
							 cin>>altura; system("cls");
						 	   while(altura <= 0){
						 	    cout<<"\a  ERROR: Ingres� una altura inv�lida.\n  Por favor vuelva a ingresar la altura de su paquete (Mayor que cero) -> "; cin>>altura;
								  } system("cls");
							 
							
							cout<<"  Ingrese la profundidad del paquete (cm) -> ";
							 cin>>profundidad; system("cls");
						 	   while(profundidad <= 0){
						 	    cout<<"\a  ERROR: Ingres� una profundidad inv�lida.\n  Por favor vuelva a ingresar la profundidad de su paquete (Mayor que cero) -> "; cin>>profundidad;
								  } system("cls");}
						else{
						contDocumentos++;}
								  
	 	cout<<"  Ingrese el peso de la encomienda (Kg)-(Mayor que cero) -> ";
	 	 cin>>pesoEncomienda; system("cls");
	 	   while(pesoEncomienda <= 0){
	 	    cout<<"\a  ERROR: Ingres� un peso inv�lido.\n  Por favor vuelva a ingresar el peso de su encomienda (Mayor que cero) -> "; cin>>pesoEncomienda;
			  } system("cls");
			  
		cout<<"  Ingrese el medio de pago: (M)edios Electr�nicos - (E)fectivo -> ";
	 	 cin>>medioPago; system("cls");
			while(medioPago != 'm' && medioPago != 'M' && medioPago != 'e' && medioPago != 'E'){
			 cout<<"\a  ERROR: Ingres� un medio de pago inv�lido. \n  Por favor vuelva a ingresar el medio de pago (M)edios Electr�nicos - (E)fectivo -> "; cin>>medioPago;
			 } system("cls");
 }
 
 

//MAIN -->

main(){
 setlocale(LC_CTYPE, "Spanish");        //Definir el idioma con el que voy a escribir para poder poner "�" y acentos
 system("color f");                     //Cambio de color de las letras del texto en la consola
 cout<<fixed;                           //Para que sirva el setprecision 
 
   //Variables
   int cedula;
   int auxIVA;
   float pesoEncomienda = 0.0, ancho = 0.0, altura = 0.0, profundidad = 0.0, pesoVolumetricoPaquete = 0.0, pesoFinal = 0.0;
   float precioSinIVA = 0.0, IVA = 0.0, precioTotal = 0.0;
   char medioPago, tipoEncomienda, respuesta = 's';
   int contFacturas = 0, contPaquetes = 0, contDocumentos = 0;
   float acumIVA = 0.0;
   float pesoMax = -1, montoMax = 0.0;
   int cedulaMax;
   float pesoVolMin = -1, montoVolMin = 0.0, pesoEncomiendaVolMin = 0.0;
   int cedulaVolMin;
   float acumMontoDocumentos = 0.0, acumMontoPaquetes = 0.0;

		cout<<"\t\t\t  BIENVENIDOS AL SISTEMA DE FACTURACI�N DE 'TuEnv�oExpress C.A'";
		cout<<"\n\t\t     Este software cumple con lo establecido en la Gaceta Oficial N� 41.239";
		cout<<"\n\t\t\t\t  Elaborado por: Carlos Fontes - 20171110221.";
		cout<<"\n\t\t\t\t\t   Universidad Metropolitana.";
		cout<<"\n\n\t\t\t  Por favor proceda a tocar una tecla y seguir las instrucciones.";
		getch(); system("cls");
	
	while(respuesta == 's' || respuesta == 'S'){
		contFacturas++;
		
		IngresoDatos(cedula, tipoEncomienda, pesoEncomienda, medioPago, profundidad, ancho, altura, contDocumentos, contPaquetes);
		pesoVolumetricoPaquete = CalculoPesoVolumetrico(ancho, altura, profundidad);
		pesoFinal = CalculoPesoFinal(tipoEncomienda, pesoEncomienda, pesoVolumetricoPaquete);
		precioSinIVA = CalculoPrecioSinIVA(pesoFinal, tipoEncomienda);
		IVA = CalculoIVA(medioPago, precioSinIVA, auxIVA, acumIVA);
		precioTotal = CalculoPrecioTotal(precioSinIVA, IVA, tipoEncomienda, acumMontoPaquetes, acumMontoDocumentos); 
		CalculoDeMaximos(pesoEncomienda, cedula, precioTotal, pesoMax, cedulaMax, montoMax, tipoEncomienda);
	    CalculoDeMinimos(pesoVolumetricoPaquete, cedula, precioTotal, pesoVolMin, cedulaVolMin, montoVolMin, tipoEncomienda, pesoEncomienda, pesoEncomiendaVolMin);

		
		cout<<"\n\t\t\t Se proceder� a imprimir su gu�a para su encomienda. Pulse una tecla...";
		getch(); system("cls");
		
		ImpresionGuia(cedula, pesoEncomienda, tipoEncomienda, pesoVolumetricoPaquete, medioPago, precioSinIVA, IVA, precioTotal, auxIVA);
		
		cout<<"\n\n\n\n\t\t\t        Desea hacer otra facturaci�n? (S)i - (N)o?"; 
		 cin>>respuesta; system("cls");
	}
	
 ImpresionFacturaFinal(contFacturas, contDocumentos, contPaquetes, pesoMax, pesoVolMin, acumMontoPaquetes, acumMontoDocumentos, pesoVolumetricoPaquete, cedulaMax, cedulaVolMin, montoMax, montoVolMin, acumIVA, tipoEncomienda, pesoEncomiendaVolMin);

getch();	
system("pause");	
return 0;	
}  
