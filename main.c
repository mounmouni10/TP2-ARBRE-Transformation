/**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>

  typedef int bool ;

  #define True 1
  #define False 0

  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tbi Type_Tbi  ;
  typedef Type_Tbi * Typestr_Tbi ;
  typedef bool Type1_Tbi  ;
  typedef int Type2_Tbi  ;
  struct Tbi
    {
      Type1_Tbi Champ1 ;
      Type2_Tbi Champ2 ;
    };

  Type1_Tbi Struct1_Tbi ( Typestr_Tbi S)
    {
      return  S->Champ1 ;
    }

  Type2_Tbi Struct2_Tbi ( Typestr_Tbi S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tbi ( Typestr_Tbi S, Type1_Tbi Val )
    {
       S->Champ1 = Val ;
    }

  void Aff_struct2_Tbi ( Typestr_Tbi S, Type2_Tbi Val )
    {
       S->Champ2 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tbi Typeelem_ATbi   ;
  typedef struct Noeud_ATbi * Pointeur_ATbi ;

  struct Noeud_ATbi
    {
      Typeelem_ATbi  Val ;
      Pointeur_ATbi Fg ;
      Pointeur_ATbi Fd ;
      Pointeur_ATbi Pere ;
     } ;

  Typeelem_ATbi Info_ATbi( Pointeur_ATbi P )
    { return P->Val;   }

  Pointeur_ATbi Fg_ATbi( Pointeur_ATbi P)
    { return P->Fg ; }

  Pointeur_ATbi Fd_ATbi( Pointeur_ATbi P)
    { return P->Fd ; }

  Pointeur_ATbi Pere_ATbi( Pointeur_ATbi P)
    { return P->Pere ; }

  void Aff_info_ATbi ( Pointeur_ATbi P, Typeelem_ATbi Val)
    {
      Typeelem_ATbi _Temp ;
      _Temp = malloc(sizeof(Type_Tbi));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATbi( Pointeur_ATbi P, Pointeur_ATbi Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATbi( Pointeur_ATbi P, Pointeur_ATbi Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATbi( Pointeur_ATbi P, Pointeur_ATbi Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATbi( Pointeur_ATbi *P)
    {
      *P = (struct Noeud_ATbi *) malloc( sizeof( struct Noeud_ATbi))   ;
      (*P)->Val = malloc(sizeof(Type_Tbi));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATbi( Pointeur_ATbi P)
    { free( P ) ; }


  /** Variables du programme principal **/
  Pointeur_ATbi A;
  Pointeur_ATbi Ag;
  Pointeur_ATbi Ad;
  Pointeur_ATbi Q;
  Pointeur_ATbi P;
  Typestr_Tbi Info_arb;
  int Val;
  int N;
  int I;
  int C;
  bool Color;
  int _Px1;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Prototypes des fonctions **/

  void Const_arb (Pointeur_ATbi *A , int *N);
  void Insert_arb (Pointeur_ATbi *A , int *Val , bool *Color);
  void Inordre (Pointeur_ATbi *A);
  void Afficher_arb (Pointeur_ATbi *A);
  void Liste_gauche (Pointeur_ATbi *A);
  void Liste_droite (Pointeur_ATbi *A);
  void Transf_prem (Pointeur_ATbi *A);
  void Affg (Pointeur_ATbi *A);
  void Affd (Pointeur_ATbi *A);
  void Gauche_i (Pointeur_ATbi *A , int *K);
  void Droite_i (Pointeur_ATbi *A , int *K);
  void Transfo_i (Pointeur_ATbi *A , int *K);
  void Gauche_iii (Pointeur_ATbi *A);
  void Droite_iii (Pointeur_ATbi *A);
  void Transfo_iii (Pointeur_ATbi *A);
  void Transfo_ii (Pointeur_ATbi *A);

  /*********************************************/
  void Const_arb (Pointeur_ATbi *A , int *N)
    {
      /** Variables locales **/
      Pointeur_ATbi Ag = NULL;
      Pointeur_ATbi Ad = NULL;
      int Val;
      int C;
      bool Color;
      int I;

      /** Corps du module **/
     for( I  =  1 ;I <=  *N - 1 ; ++I){
       Val  =  Aleanombre(100 ) + 1 ;
       C  =  Aleanombre(2 ) ;
       if( ( C == 0 )) {
         Color  =  False ;
         Insert_arb ( & Ag , & Val , & Color ) ;
         }
       else
         {
         Color  =  True ;
         Insert_arb ( & Ad , & Val , & Color ) ;

       } ;

     } ;
     Creernoeud_ATbi (& *A ) ;
     Aff_struct1_Tbi ( Info_arb  , False ) ;
     Aff_struct2_Tbi ( Info_arb  , 10000 ) ;
     Aff_info_ATbi ( *A , Info_arb ) ;
     Aff_fg_ATbi ( *A , Ag ) ;
     Aff_fd_ATbi ( *A , Ad ) ;

    }
  /*------------------------------------------*/
  void Insert_arb (Pointeur_ATbi *A , int *Val , bool *Color)
    {
      /** Variables locales **/
      Pointeur_ATbi P;
      Typestr_Tbi Info_arb;

      /** Corps du module **/
     Info_arb = malloc(sizeof(Type_Tbi));
     if( ( *A == NULL )) {
       Creernoeud_ATbi (& *A ) ;
       Aff_struct1_Tbi ( Info_arb  , *Color ) ;
       Aff_struct2_Tbi ( Info_arb  , *Val ) ;
       Aff_info_ATbi ( *A , Info_arb ) ;
       }
     else
       {
       if( ( Struct2_Tbi ( Info_ATbi ( *A )  ) > *Val )) {
         P  =  Fg_ATbi ( *A ) ;
         Insert_arb ( & P , & *Val , & *Color ) ;
         Aff_fg_ATbi ( *A , P ) ;
         }
       else
         {
         if( ( Struct2_Tbi ( Info_ATbi ( *A )  ) < *Val )) {
           P  =  Fd_ATbi ( *A ) ;
           Insert_arb ( & P , & *Val , & *Color ) ;
           Aff_fd_ATbi ( *A , P ) ;
           }
         else
           {
           *Val  =  Aleanombre(100 ) + 1 ;
           C  =  Aleanombre(2 ) ;
           if( ( C == 0 )) {
             *Color  =  False ;
             Insert_arb ( & Ag , & *Val , & *Color ) ;
             }
           else
             {
             *Color  =  True ;
             Insert_arb ( & Ad , & *Val , & *Color ) ;

           } ;
           Insert_arb ( & *A , & *Val , & *Color ) ;

         } ;

       } ;

     } ;

    }
  /*----------------------------*/
  void Inordre (Pointeur_ATbi *A)
    {
      /** Variables locales **/
      Pointeur_ATbi _Px1;
      Type_Tbi _Struct_Temp1;
      Pointeur_ATbi _Px2;

      /** Corps du module **/
     if( ( *A != NULL )) {
       _Px1 =  Fg_ATbi ( *A ) ;
       Inordre ( &_Px1) ;
       /** Ecriture d'une structure */
       _Struct_Temp1 = *Info_ATbi(*A);
       printf ( " %d", _Struct_Temp1.Champ1 );
       printf ( " %d", _Struct_Temp1.Champ2 );
       printf ( " %s", "|" ) ;
       _Px2 =  Fd_ATbi ( *A ) ;
       Inordre ( &_Px2) ;
       printf ( " %s", " " ) ;

     } ;

    }
  /*---------------------------------------------------------------------*/
  void Afficher_arb (Pointeur_ATbi *A)
    {

      /** Corps du module **/
     if( ( *A != NULL )) {
       Inordre ( & *A ) ;
       }
     else
       {
       printf ( " %s", " ERREUR " ) ;

     } ;

    }
  /*------------------------------------------------------------------*/
  void Liste_gauche (Pointeur_ATbi *A)
    {
      /** Variables locales **/
      Pointeur_ATbi Q;
      Pointeur_ATbi P;
      Pointeur_ATbi R;
      Pointeur_ATbi _Px1;

      /** Corps du module **/
     P  =  Fg_ATbi ( *A ) ;
     if( ( P != NULL )) {
       ;
       if( ( Fd_ATbi ( P ) != NULL )) {
         if( ( Fg_ATbi ( Fd_ATbi ( P ) ) == NULL )) {
           Aff_fg_ATbi ( Fd_ATbi ( P ) , P ) ;
           Aff_fg_ATbi ( *A , Fd_ATbi ( P ) ) ;
           Aff_fd_ATbi ( Fg_ATbi ( Fd_ATbi ( P ) ) , NULL ) ;
           }
         else
           {
           R  =  Fg_ATbi ( Fd_ATbi ( P ) ) ;
           while( ( Fg_ATbi ( R ) != NULL )) {
             R  =  Fg_ATbi ( R ) ;

           } ;
           Aff_fg_ATbi ( R , Fg_ATbi ( *A ) ) ;
           Aff_fg_ATbi ( *A , Fd_ATbi ( P ) ) ;
           Aff_fd_ATbi ( Fg_ATbi ( R ) , NULL ) ;

         } ;
         Liste_gauche ( & *A ) ;
         }
       else
         {
         _Px1 =  Fg_ATbi ( *A ) ;
         Liste_gauche ( &_Px1) ;

       } ;

     } ;

    }
  /*------------------------------------------------------*/
  void Liste_droite (Pointeur_ATbi *A)
    {
      /** Variables locales **/
      Pointeur_ATbi Q;
      Pointeur_ATbi P;
      Pointeur_ATbi R;
      Pointeur_ATbi _Px1;

      /** Corps du module **/
     P  =  Fd_ATbi ( *A ) ;
     if( ( P != NULL )) {
       ;
       if( ( Fg_ATbi ( P ) != NULL )) {
         if( ( Fd_ATbi ( Fg_ATbi ( P ) ) == NULL )) {
           Aff_fd_ATbi ( Fg_ATbi ( P ) , P ) ;
           Aff_fd_ATbi ( *A , Fg_ATbi ( P ) ) ;
           Aff_fg_ATbi ( Fd_ATbi ( Fg_ATbi ( P ) ) , NULL ) ;
           }
         else
           {
           R  =  Fd_ATbi ( Fg_ATbi ( P ) ) ;
           while( ( Fd_ATbi ( R ) != NULL )) {
             R  =  Fd_ATbi ( R ) ;

           } ;
           Aff_fd_ATbi ( R , Fd_ATbi ( *A ) ) ;
           Aff_fd_ATbi ( *A , Fg_ATbi ( P ) ) ;
           Aff_fg_ATbi ( Fd_ATbi ( R ) , NULL ) ;

         } ;
         Liste_droite ( & *A ) ;
         }
       else
         {
         _Px1 =  Fd_ATbi ( *A ) ;
         Liste_droite ( &_Px1) ;

       } ;

     } ;

    }
  /*--------------------------------------------*/
  void Transf_prem (Pointeur_ATbi *A)
    {

      /** Corps du module **/
     Liste_gauche ( & *A ) ;
     Liste_droite ( & *A ) ;

    }
  /*----------------------------------------------------*/
  void Affg (Pointeur_ATbi *A)
    {
      /** Variables locales **/
      Pointeur_ATbi P;
      Type_Tbi _Struct_Temp2;
      Type_Tbi _Struct_Temp3;

      /** Corps du module **/
     P  =  Fg_ATbi ( *A ) ;
     while( ( P != NULL )) {
       /** Ecriture d'une structure */
       _Struct_Temp2 = *Info_ATbi(P);
       printf ( " %d", _Struct_Temp2.Champ1 );
       printf ( " %d", _Struct_Temp2.Champ2 );
       printf ( " %s", "|" ) ;
       if( ( Fd_ATbi ( P ) == NULL )) {
         printf ( " %s", "je suis vide" ) ;
         }
       else
         {
         printf ( " %s", "je ne suis pas vide" );
         /** Ecriture d'une structure */
         _Struct_Temp3 = *Info_ATbi(Fd_ATbi(P));
         printf ( " %d", _Struct_Temp3.Champ1 );
         printf ( " %d", _Struct_Temp3.Champ2 ) ;

       } ;
       P  =  Fg_ATbi ( P ) ;

     } ;

    }
  /*----------------------------------------------*/
  void Affd (Pointeur_ATbi *A)
    {
      /** Variables locales **/
      Pointeur_ATbi P;
      Type_Tbi _Struct_Temp4;
      Type_Tbi _Struct_Temp5;

      /** Corps du module **/
     P  =  Fd_ATbi ( *A ) ;
     while( ( P != NULL )) {
       /** Ecriture d'une structure */
       _Struct_Temp4 = *Info_ATbi(P);
       printf ( " %d", _Struct_Temp4.Champ1 );
       printf ( " %d", _Struct_Temp4.Champ2 );
       printf ( " %s", "|" ) ;
       if( ( Fg_ATbi ( P ) == NULL )) {
         printf ( " %s", "je suis vide" ) ;
         }
       else
         {
         printf ( " %s", "je ne suis pas vide" );
         /** Ecriture d'une structure */
         _Struct_Temp5 = *Info_ATbi(Fg_ATbi(P));
         printf ( " %d", _Struct_Temp5.Champ1 );
         printf ( " %d", _Struct_Temp5.Champ2 ) ;

       } ;
       P  =  Fd_ATbi ( P ) ;

     } ;

    }
  /*-----------------------------------------------*/
  void Gauche_i (Pointeur_ATbi *A , int *K)
    {
      /** Variables locales **/
      Pointeur_ATbi P;
      Pointeur_ATbi Q;
      int I;
      int N;

      /** Corps du module **/
     P  =  Fg_ATbi ( *A ) ;
     N  =  1 ;
     I  =  *K ;
     while( ( ( P != NULL ) )) {
       Q  =  Fg_ATbi ( P ) ;
       if( ( Q != NULL )) {
         Aff_fd_ATbi ( P , Q ) ;
         Aff_fg_ATbi ( P , NULL ) ;
         while( ( ( Fg_ATbi ( Q ) != NULL ) && ( N < I ) )) {
           Aff_fd_ATbi ( Q , Fg_ATbi ( Q ) ) ;
           Aff_fg_ATbi ( Q , NULL ) ;
           Q  =  Fd_ATbi ( Q ) ;
           N  =  N + 1 ;

         } ;
         if( ( ( Fg_ATbi ( Q ) != NULL ) )) {
           Aff_fg_ATbi ( P , Fg_ATbi ( Q ) ) ;
           Aff_fg_ATbi ( Q , NULL ) ;
           P  =  Fg_ATbi ( P ) ;
           N  =  1 ;
           I  =  I + *K ;
           }
         else
           {
           P  =  NULL ;

         } ;
         }
       else
         {
         P  =  NULL ;

       } ;

     } ;

    }
  /*-----------------------------------------------*/
  void Droite_i (Pointeur_ATbi *A , int *K)
    {
      /** Variables locales **/
      Pointeur_ATbi P;
      Pointeur_ATbi Q;
      int I;
      int N;

      /** Corps du module **/
     P  =  Fd_ATbi ( *A ) ;
     N  =  1 ;
     I  =  *K ;
     while( ( ( P != NULL ) )) {
       Q  =  Fd_ATbi ( P ) ;
       if( ( Q != NULL )) {
         Aff_fg_ATbi ( P , Q ) ;
         Aff_fd_ATbi ( P , NULL ) ;
         while( ( ( Fd_ATbi ( Q ) != NULL ) && ( N < I ) )) {
           Aff_fg_ATbi ( Q , Fd_ATbi ( Q ) ) ;
           Aff_fd_ATbi ( Q , NULL ) ;
           Q  =  Fg_ATbi ( Q ) ;
           N  =  N + 1 ;

         } ;
         if( ( ( Fd_ATbi ( Q ) != NULL ) )) {
           Aff_fd_ATbi ( P , Fd_ATbi ( Q ) ) ;
           Aff_fd_ATbi ( Q , NULL ) ;
           P  =  Fd_ATbi ( P ) ;
           N  =  1 ;
           I  =  I + *K ;
           }
         else
           {
           P  =  NULL ;

         } ;
         }
       else
         {
         P  =  NULL ;

       } ;

     } ;

    }
  /*------------------------------------------------*/
  void Transfo_i (Pointeur_ATbi *A , int *K)
    {

      /** Corps du module **/
     Gauche_i ( & *A , & *K ) ;
     Affg ( & *A ) ;
     Droite_i ( & *A , & *K ) ;
     Affd ( & *A ) ;

    }
  /*-----------------------------------------------*/
  void Gauche_iii (Pointeur_ATbi *A)
    {
      /** Variables locales **/
      Pointeur_ATbi P;
      Pointeur_ATbi Q;
      int I;
      int N;
      int K;

      /** Corps du module **/
     P  =  Fg_ATbi ( *A ) ;
     while( ( ( P != NULL ) )) {
       K  =  Aleanombre(3 ) + 1 ;
       N  =  1 ;
       Q  =  Fg_ATbi ( P ) ;
       if( ( Q != NULL )) {
         Aff_fd_ATbi ( P , Q ) ;
         Aff_fg_ATbi ( P , NULL ) ;
         while( ( ( Fg_ATbi ( Q ) != NULL ) && ( N < K ) )) {
           Aff_fd_ATbi ( Q , Fg_ATbi ( Q ) ) ;
           Aff_fg_ATbi ( Q , NULL ) ;
           Q  =  Fd_ATbi ( Q ) ;
           N  =  N + 1 ;

         } ;
         if( ( ( Fg_ATbi ( Q ) != NULL ) )) {
           Aff_fg_ATbi ( P , Fg_ATbi ( Q ) ) ;
           Aff_fg_ATbi ( Q , NULL ) ;
           P  =  Fg_ATbi ( P ) ;
           }
         else
           {
           P  =  NULL ;

         } ;
         }
       else
         {
         P  =  NULL ;

       } ;

     } ;

    }
  /*-----------------------------------------------*/
  void Droite_iii (Pointeur_ATbi *A)
    {
      /** Variables locales **/
      Pointeur_ATbi P;
      Pointeur_ATbi Q;
      int I;
      int N;
      int K;

      /** Corps du module **/
     P  =  Fd_ATbi ( *A ) ;
     while( ( ( P != NULL ) )) {
       Q  =  Fd_ATbi ( P ) ;
       N  =  1 ;
       K  =  Aleanombre(3 ) + 1 ;
       if( ( Q != NULL )) {
         Aff_fg_ATbi ( P , Q ) ;
         Aff_fd_ATbi ( P , NULL ) ;
         while( ( ( Fd_ATbi ( Q ) != NULL ) && ( N < K ) )) {
           Aff_fg_ATbi ( Q , Fd_ATbi ( Q ) ) ;
           Aff_fd_ATbi ( Q , NULL ) ;
           Q  =  Fg_ATbi ( Q ) ;
           N  =  N + 1 ;

         } ;
         if( ( ( Fd_ATbi ( Q ) != NULL ) )) {
           Aff_fd_ATbi ( P , Fd_ATbi ( Q ) ) ;
           Aff_fd_ATbi ( Q , NULL ) ;
           P  =  Fd_ATbi ( P ) ;
           }
         else
           {
           P  =  NULL ;

         } ;
         }
       else
         {
         P  =  NULL ;

       } ;

     } ;

    }
  /*---------------------------------*/
  void Transfo_iii (Pointeur_ATbi *A)
    {

      /** Corps du module **/
     Gauche_iii ( & *A ) ;
     Affg ( & *A ) ;
     Droite_iii ( & *A ) ;
     Affd ( & *A ) ;

    }
  /*------------------------------------------*/
  void Transfo_ii (Pointeur_ATbi *A)
    {
      /** Variables locales **/
      Pointeur_ATbi Pg;
      Pointeur_ATbi Pd;
      Pointeur_ATbi Qd;
      Pointeur_ATbi Qg;
      int N;
      int K;
      int I;

      /** Corps du module **/
     Pg  =  Fg_ATbi ( *A ) ;
     Pd  =  Fd_ATbi ( *A ) ;
     while( ( ( Pg != NULL ) && ( Pd != NULL ) )) {
       K  =  Aleanombre(3 ) + 1 ;
       N  =  1 ;
       Qg  =  Fg_ATbi ( Pg ) ;
       Qd  =  Fd_ATbi ( Pd ) ;
       if( ( Q != NULL )) {
         Aff_fg_ATbi ( Pd , Qd ) ;
         Aff_fd_ATbi ( Pd , NULL ) ;
         while( ( ( Fd_ATbi ( Qd ) != NULL ) && ( N < K ) )) {
           Aff_fg_ATbi ( Qd , Fd_ATbi ( Qd ) ) ;
           Aff_fd_ATbi ( Qd , NULL ) ;
           Qd  =  Fg_ATbi ( Qd ) ;
           N  =  N + 1 ;

         } ;
         if( ( ( Fd_ATbi ( Qd ) != NULL ) )) {
           Aff_fd_ATbi ( Pd , Fd_ATbi ( Qd ) ) ;
           Aff_fd_ATbi ( Qd , NULL ) ;
           Pd  =  Fd_ATbi ( Pd ) ;
           }
         else
           {
           Pd  =  NULL ;

         } ;
         }
       else
         {
         Pd  =  NULL ;

       } ;
       N  =  1 ;
       if( ( Qg != NULL )) {
         Aff_fd_ATbi ( Pg , Qg ) ;
         Aff_fg_ATbi ( Pg , NULL ) ;
         while( ( ( Fg_ATbi ( Qg ) != NULL ) && ( N < K ) )) {
           Aff_fd_ATbi ( Qg , Fg_ATbi ( Qg ) ) ;
           Aff_fg_ATbi ( Qg , NULL ) ;
           Qg  =  Fd_ATbi ( Qg ) ;
           N  =  N + 1 ;

         } ;
         if( ( ( Fg_ATbi ( Qg ) != NULL ) )) {
           Aff_fg_ATbi ( Pg , Fg_ATbi ( Qg ) ) ;
           Aff_fg_ATbi ( Qg , NULL ) ;
           Pg  =  Fg_ATbi ( Pg ) ;
           }
         else
           {
           Pg  =  NULL ;

         } ;
         }
       else
         {
         Pg  =  NULL ;

       } ;

     } ;
     if( ( ( Pg == NULL ) && ( Pd != NULL ) )) {
       while( ( ( Pd != NULL ) )) {
         Qd  =  Fd_ATbi ( Pd ) ;
         N  =  1 ;
         K  =  Aleanombre(3 ) + 1 ;
         if( ( Qd != NULL )) {
           Aff_fg_ATbi ( Pd , Qd ) ;
           Aff_fd_ATbi ( Pd , NULL ) ;
           while( ( ( Fd_ATbi ( Qd ) != NULL ) && ( N < K ) )) {
             Aff_fg_ATbi ( Qd , Fd_ATbi ( Qd ) ) ;
             Aff_fd_ATbi ( Qd , NULL ) ;
             Qd  =  Fg_ATbi ( Qd ) ;
             N  =  N + 1 ;

           } ;
           if( ( ( Fd_ATbi ( Qd ) != NULL ) )) {
             Aff_fd_ATbi ( Pd , Fd_ATbi ( Qd ) ) ;
             Aff_fd_ATbi ( Qd , NULL ) ;
             Pd  =  Fd_ATbi ( Pd ) ;
             }
           else
             {
             Pd  =  NULL ;

           } ;
           }
         else
           {
           Pd  =  NULL ;

         } ;

       } ;
       }
     else
       {
       while( ( ( Pg != NULL ) )) {
         K  =  Aleanombre(3 ) + 1 ;
         N  =  1 ;
         Qg  =  Fg_ATbi ( Pg ) ;
         if( ( Qg != NULL )) {
           Aff_fd_ATbi ( Pg , Qg ) ;
           Aff_fg_ATbi ( Pg , NULL ) ;
           while( ( ( Fg_ATbi ( Qg ) != NULL ) && ( N < K ) )) {
             Aff_fd_ATbi ( Qg , Fg_ATbi ( Qg ) ) ;
             Aff_fg_ATbi ( Qg , NULL ) ;
             Qg  =  Fd_ATbi ( Qg ) ;
             N  =  N + 1 ;

           } ;
           if( ( ( Fg_ATbi ( Qg ) != NULL ) )) {
             Aff_fg_ATbi ( Pg , Fg_ATbi ( Qg ) ) ;
             Aff_fg_ATbi ( Qg , NULL ) ;
             Pg  =  Fg_ATbi ( Pg ) ;
             }
           else
             {
             Pg  =  NULL ;

           } ;
           }
         else
           {
           Pg  =  NULL ;

         } ;

       } ;

     } ;

    }
    //Procédure qui permet de générer le fichier (.dot) utilisé pour le dessin de l'arbre
void dessinArbre (Pointeur_ATbi *A, FILE* f, int* nbNil)
{

    if (A != NULL)
    {
        // Dessiner un arc vers le fils gauche
        if (Fg_ATbi ( A ) != NULL)
        {
            fprintf(f, "  \"%d\" -- \"%d\" \n", Info_ATbi(A)->Champ2, Info_ATbi(Fg_ATbi(A))->Champ2);
        }
        else
        {
            fprintf(f, "  \"NIL%d\" [style=invis];\n", *nbNil);
            fprintf(f, "  \"%d\" -- \"NIL%d\" ", Info_ATbi(A)->Champ2, (*nbNil)++);
            fprintf(f, " [style=invis];\n");
        }

        // Dessiner un fils NIL virtuel et invisible au milieu (pour une meilleure séparation des fils gauches et droits)
        fprintf(f, "  \"NIL%d\" [style=invis];\n", *nbNil);
        fprintf(f, "  \"%d\" -- \"NIL%d\" ",Info_ATbi(A)->Champ2, (*nbNil)++);
        fprintf(f, " [style=invis];\n");

        // Dessiner un arc vers le fils droit
        if (Fd_ATbi( A )!= NULL)
        {
            fprintf(f, "  \"%d\" -- \"%d\" \n",Info_ATbi(A)->Champ2, Info_ATbi(Fd_ATbi(A))->Champ2);
        }
        else
        {
            fprintf(f, "  \"NIL%d\" [style=invis];\n", *nbNil);
            fprintf(f, "  \"%d\" -- \"NIL%d\" ",Info_ATbi(A)->Champ2, (*nbNil)++);
            fprintf(f, " [style=invis];\n");
        }

        // Dessiner les sous-arbres gauche et droit
        dessinArbre(Fg_ATbi ( A ), f, nbNil);
        dessinArbre(Fd_ATbi ( A ), f, nbNil);
   }
}

  int main(int argc, char *argv[])
    {

    char nomf[50];      // Utilisée pour contenir le nom du fichier
    char cmd[100];      // Utilisée pour exécuter la commande système qui permet de dessiner l'arbre
    int n;
    int sortie = 1;     // Utilisée pour les noms des fichiers du dessin de l'arbre
    int nbNil;// Utilisée dans (dessinerArbre) pour le dessin de l'arbre
    int choix;
    int refaire=1;

    FILE *f;

     Info_arb = malloc(sizeof(Type_Tbi));
   while(refaire==1)


{
     printf("ENTRER VOTRE CHOIX ");
     printf ("\n l'arbre creer \n");
     printf ("\n2- l'arbre apres la premiere transformation\n");
     printf ("\n3-l'arbre apres la 2eme transformation I\n");
     printf ("\n4-'arbre apres la 2eme transformation II\n");
     printf ("\n5-l'arbre apres la 2eme transformation III\n");
     printf("\n6- dessin de l'arbre\n");
     scanf("%d", &choix);
    switch (choix)
    {
      case 1 ://Dessiner l'arbre créer
      printf ( " donner n \n " ) ;
     scanf ( " %d", &N ) ;
     Const_arb ( &A , & N ) ;

         break;
         //***********************************************************************************
         case 2://1ere transromation
            Transf_prem ( & A ) ;

            break;
         //*************************************************************************************
          case 3:// AUTRES  TRANSFORMATION  I
            Transf_prem ( & A ) ;
            _Px1 =   1;
            Transfo_i ( & A , &_Px1) ;

            break;
            case 4://AUTRES TRANSFORMATION II
            Transf_prem ( & A ) ;
            Transfo_ii ( & A ) ;

            break;


          case 5 ://AUTRES TRANSFORMATION III
        Transf_prem ( & A ) ;
        Transfo_iii ( & A ) ;

            break;

          case 6://dessiner l'arbre
               printf ("Dessin de l'arbre \n");
               printf ("   ----------------- \n\n");
            if (A == NULL)
                    {
                        printf ("> ERREUR : Arbre vide !");
                    }
                    else
                    {
                        sprintf(nomf, "arbre%d.dot", sortie);
                        f = fopen(nomf,"w");        // Ouverture du fichier en écriture.
                        fprintf(f, "graph arbre {\n");
                        fprintf(f, "\tordering = out;\n");
                        fprintf(f, "\tsplines = false;\n");
                        nbNil = 0;
                        dessinArbre(A, f, &nbNil);
                        fprintf(f, "}\n");
                        fclose(f);
                        sprintf(cmd, "dot -Tpng arbre%d.dot -o arbre%d.png", sortie, sortie);
                        system(cmd);
                        sprintf(cmd, "arbre%d.png", sortie);
                        system(cmd);
                        sortie++;
                        printf (">> L'arbre est dessine correctement !");
                    }

                    fflush(stdin);
                    getchar();

        break;
          default:
             printf("Choix incorrect.\n");
    }
    if (refaire==1)
      {

      printf("\n");
      printf("\n");
      printf("\n");
      printf(" ______________________________________________________________\n");
      printf("|                                                              |\n");
      printf("|                 Que voulez faire desormais?                  |\n");
      printf("|                                                              |\n");
      printf("|       1- Retourner au menu principal.                        |\n");
      printf("|       2- Quitter le programme.                               |\n");
      printf("|                                                              |\n");
      printf("|______________________________________________________________|\n");


        printf("\n");

      printf("\n Entrez le numero de votre choix : ");
      scanf("%d", &choix);

      if (choix!=1) refaire=0;
      }
/*
     Info_arb = malloc(sizeof(Type_Tbi));
     printf (" donner n \n" ) ;
     scanf ( "%d", &N ) ;
    printf (" \n--------------------------------------------------------- \n" ) ;
     Const_arb ( & A , & N ) ;
     printf ( " \nARB cree est: \n " ) ;
     Afficher_arb ( & A ) ;
     printf ( " \n-------------------------------------------------------- \n" ) ;
     printf ( " \nARB aprés 1 ere transformation:\n " ) ;
     Transf_prem ( & A ) ;
     Afficher_arb ( & A ) ;
     printf ( " \n******************************************\n" ) ;
     printf ( " \n arb gauche de la premiere transformation:\n" ) ;
     Affg ( & A ) ;
    printf ( " \n******************************************\n" ) ;
     printf ( " \n arb droit  de la premiere transformation:\n" ) ;
     Affd ( & A ) ;
     printf (" \n-----------------------------------------------\n " ) ;
     printf ( " \n 2eme transformation \n  " ) ;
     printf("\n transformation i:\n");
     _Px1 =  2 ;
     Transfo_i ( & A , &_Px1) ;
     printf ( " \n--------------------------------------------\n " ) ;
     printf ( "\n---------------------------------------------\n " ) ;
     printf("\n transformation iii:\n");
     Transfo_iii ( & A ) ;
     printf ( "\n--------------------------------------------\n" ) ;
     printf("\n transformation iii:\n");
     Transfo_ii ( & A ) ;*/
}

      system("PAUSE");
      return 0;
    }
