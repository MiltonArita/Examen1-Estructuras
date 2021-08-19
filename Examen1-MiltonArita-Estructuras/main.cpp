#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 struct Nodo{
 	int dato;
 	Nodo *siguiente;
};

//void agregar1(Nodo *&,int);         no se ocupa
void agregar2(Nodo *&,Nodo*&,int);
void sacar2(Nodo *&,int &);
bool agregar3(Nodo *);
//void sacar1(Nodo *&,Nodo *&,int &);  no se ocupa
bool lista_vacia(Nodo *);



int main(int argc, char** argv) {
	//Menu para insertar y sacar cajas del almacen
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato;
	int cajas,peso; 
	cout<<"Cuantas Cajas Ingresaran al Almacen"<<endl;
	cin>>cajas;
	for(int x=0;x<cajas;x++){
	cout<<"Ingrese Codigo De Barra de la Caja "<<x+1<<": ";
    cin>>dato;
    cout<<"Ingrese el Peso en libras de la Caja "<<x+1<<": ";
    cin>>peso;
    agregar2(frente,fin,dato);          //llenando almacen
	}
    
     cout<<"---------------------------------------------"<<endl;
     cout<<"Se ingresaron "<<cajas<<" Cajas al Almacen"<<endl;
     cout<<""<<endl;
    cout<<"Desea Despachar las "<<cajas<<" Cajas : "<<endl;
    cout<<"1-) SI " <<endl;
	cout<<"2-) NO " <<endl;
	cout<<"Opcion a Elegir : ";
	int opc;
	cin>>opc;
    if(opc==1){
    	 cout<<""<<endl;
    	cout<<"Despachando Cajas con Codigo : ";
    	//sacando las cajas
    while(frente!=NULL){
        sacar2(frente,dato);
        if(frente!=NULL){
            cout<<dato<<" , ";
        }
        else{
             cout<<dato<<" . ";
             cout<<""<<endl;
             cout<<""<<endl;
             cout<<"La Cantidad de Cajas sobrantes en el Almacen son : "<<frente<<endl;
        }
    }
	}
	else{
		//Opcion 2
		//si no despacha las cajas se quedaran almacenadas
		cout<<""<<endl;
		 cout<<"Se Quedaran Almacenadas "<<cajas<<" Cajas"<<endl;
	}
	
    
	return 0;
}


bool lista_vacia(Nodo *frente){							//inicializar lista_vacia
	return (frente==NULL)? true : false;
}

void sacar2(Nodo *&lista,int &n){
 Nodo *aux=lista;
 n=aux->dato;
 lista=aux->siguiente;
 delete aux;
}
void agregar2(Nodo *&frente,Nodo *&fin,int n){
 Nodo *nuevo_nodo=new Nodo();
 nuevo_nodo-> dato=n;
 nuevo_nodo-> siguiente=NULL;
 if(lista_vacia(frente))
 { frente=nuevo_nodo; }
 else{ fin->siguiente=nuevo_nodo; }
 fin=nuevo_nodo;
 cout<<""<<endl;
 cout<<"\tCaja con Codigo "<<n<<" insertado correctamente"<<endl;
 cout<<""<<endl;
}

