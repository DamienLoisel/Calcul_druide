#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 100

int pile[TAILLE_MAX];
int sommet = -1;

// Fonction pour ajouter des éléments à la pile
void empiler(int x) {
  pile[++sommet] = x;
}

// Fonction pour retirer des éléments de la pile
int depiler() {
  if (sommet == -1) {
    printf("Erreur: la pile est vide\n");
    exit(1);
  }
  return pile[sommet--];
}

// Fonction pour effectuer les opérations
int effectuer_operation(char operation) {
  int operande2 = depiler();// On dépile les 2 opérateurs
  int operande1 = depiler();
  if (operation == '/' && operande2 == 0) { //On vérifie si c'est un division par zéro
    printf("Erreur: division par zéro\n");
    exit(1);
  }
  if (operation == '+') return operande1 + operande2;// On effectue l'opération en fonction de l'opérateur
  if (operation == '-') return operande1 - operande2;
  if (operation == '*') return operande1 * operande2;
  if (operation == '/') return operande1 / operande2;
  if (operation == '^') return operande1 ^ operande2;
  printf("Erreur: opération invalide\n");

  exit(1);
}

// Fonction pour vérifier si c'est un chiffre
int est_chiffre(char c) {
  return c >= '0' && c <= '9';
}

// Fonction pour la saisie
char * obtenir_saisie() {
  static char saisie[TAILLE_MAX];
  printf("Entrez une expression RPN: ");
  fgets(saisie, TAILLE_MAX, stdin);
  return saisie;
}

int main() {
  char * saisie = obtenir_saisie();//On récupère la saisie
  char * p = strtok(saisie, " "); //On découpe la saisie avec un espace comme séparateur
  while (p != NULL) {
    if (est_chiffre( * p)) {//Si c'est un chiffre alors
      empiler(atoi(p));//On rajoute à la pile
    } else {//Sinon
      empiler(effectuer_operation( * p));//On effectue l'opération
    }
    p = strtok(NULL, " ");
  }
  printf("Résultat: %d\n", depiler());//On affiche le résultat du haut de la pile
  return 0;
}