#include <iostream>
#include <cstring>
#include<fstream>
using namespace std;
ifstream in("data.txt");
ofstream out("data2.txt");

int main()
{

    char M[100][100][10],cuvant[100],aux[100];
    int nrStari,st,dr,i,j,nrMuchii,stareInitiala,stareCurenta,nrStariFinale,stariFinale[1000];
    char val[100];
    bool valid=true;
    char* test;

    test=new char[1];


    //cout<<"Cuvant:";
    in.get(cuvant,100);
    in.get();

    //cout<<"Numar noduri/stari:";
    in>>nrStari;
        for(i=0;i<nrStari;i++)
        for(j=0;j<nrStari;j++)
            strcpy(M[i][j],"#");

/*
    for(i=0;i<nrStari;i++)
    {
        for(j=0;j<nrStari;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }

*/

    //cout<<"Numar muchii/actiuni:"<<endl;
    in>>nrMuchii;

    for(i=0;i<nrMuchii;i++)
    {
        //cout<<"stanga,dreapta,actiune"<<endl;
        in>>st>>dr>>val;
        if(strcmp(M[st][dr],"#")==0)
            strcpy(M[st][dr],val);
        else strcat(M[st][dr],val);
    }

    /*
        for(i=0;i<nrStari;i++)
    {
        for(j=0;j<nrStari;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
    */

    //cout<<"Stare initiala,stare finala"<<endl;
    in>>stareInitiala;
    in>>nrStariFinale;
    for(i=0;i<nrStariFinale;i++)
        in>>stariFinale[i];

    stareCurenta=stareInitiala;

            out<<stareCurenta;
    while(strlen(cuvant)!=0 && valid==true)
    {
        valid=false;
        strcpy(aux,cuvant);
        strcpy(aux+1,aux+strlen(aux));
        strcpy(test,aux);
        strcpy(cuvant,cuvant+1);


        for(j=0;j<nrStari;j++)
            if(strchr(M[stareCurenta][j],test[0])!=NULL)
            {
                out<<"---("<<test[0]<<")--->";
                stareCurenta=j;
                out<<stareCurenta;
                valid=true;
                break;
            }
    }

    out<<endl;

    if(valid==false)
        out<<"Cuvant NEacceptat. Acesta a fost drumul maxim care a putut fi parcurs.";
    else{

        for(i=0;i<nrStariFinale;i++)
            if(stareCurenta==stariFinale[i] && valid==true)
                {
                    out<<"Cuvant acceptat";
                    valid=false;//daca cuvantul este acceptat nu mai avem nevoie de valid, il folosim ca sa nu mai intram in urmatorul if
                    //daca nu se gaseste nicio stare finala, valid ramane true, intra in urmatorul if si afiseaza neacceptat
                    break;
                }

        if(valid==true)
            out<<"Cuvant NEacceptat. Cuvantul nu duce intr-o stare finala.";

        }

    return 0;
}
