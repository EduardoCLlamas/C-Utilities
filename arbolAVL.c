#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};


int max(int a, int b);
 int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Realizar rotación
    x->right = y;
    y->left = T2;

    // actualizar alturas
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // devolver raiz
    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Realizar Rotacion
    y->left = x;
    x->right = T2;

    //  actualizar alturas
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // devolver raiz
    return y;
}

// Factor de Balance
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key)
{
    /* 1.  Insercion normal */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* 2. actualizar altura del nodo predecesor */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Obtener el factor de balance del nodo predecesor */
    int balance = getBalance(node);

    // Rotar en caso de que el factor de balance no esté entre -1, 0 y 1

    // Doble rotacion a la izquierda
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Doble rotacion a la derecha
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Rotacion a la derecha
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Rotacion a la izquierda
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}

struct pseudopila
{
   int tam;//contador para las localidades del arreglo
   int cont;
   struct node *enlace[10000];//el arreglo de punteros a nodos
};

void imprime (struct node *nod)
{
     struct pseudopila x; //se crea una estructura pseudopila llamada "x"
     struct node *enlace; //secrea un apuntador a estructura node
     x.enlace[0]=nod;//en el primer miemro del arreglo de la estructura "x" se guarda la raiz
     x.tam=0;//se inicializa en cero las localidades?
     while(x.tam>=0) //mientras el tamaño sea mayor o igual a cero se repite
     {
           enlace=x.enlace[x.tam--];//al apuntador a nodo se le asigna lo que tiene en su pocición actual "0 inicial" (la raiz)
           printf("\n%d ",enlace->key);//y se posdecrementa el tamaño "-1"

           if(enlace->right != NULL) //si a lo que apunta la derecha del nodo actual(raiz) es diferente de null, tiene elementos
               x.enlace[++x.tam]=enlace->right;//se guarda en la localidad del arreglo de la estructura en la pos (0) debido al preincremento
           if(enlace->left != NULL)//si el elemento izquierdo tiene elementos "siempre comienza con la izq"
               x.enlace[++x.tam]=enlace->left;// almacena en el arreglo de la estructura la dirección del nodo izquierdo para su futura evaluación
     }//regresa al inicio del ciclo para evaluar el contenido
}



int main()
{
  struct node *root = NULL; //apuntador a estructura node señalado a null

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* Arbol construido
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  printf("Recorrido en preOrden \n");
  preOrder(root);
  printf("Recorrido \n");
  imprime(root);

  return 0;
}
