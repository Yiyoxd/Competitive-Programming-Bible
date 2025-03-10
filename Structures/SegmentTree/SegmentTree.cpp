#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    > Structure created by Daniel Juarez
    > Last modified on 02/03/2025

    What is Segment tree? 
    The segment tree is a structure that helps us in problems of queries, updates or intervals of an array.
*/

struct segmentTree{
    //segment tree vector
    vector<int> st;
    int n; //Size

    /**
     * This method initializes the vector size to a size of 4*n. This is to ensure to have enough size.
     */
    void init(int n){
        this->n = n;
        st.resize(4*n,0);
    }

    /**
     * This method constructs the segment tree with a range with two limits, start and end. These limits help us to maintain the value of a range. * The segment tree is built through recursive calls and dividing the range, until reaching leaf nodes.
     */
    void build(int start, int ending, int currentNode, vector<int>& vec){//private
        if(start == ending){
            st[currentNode] = vec[start];
            return;
        }

        int mid = (start+ending)/2;
        //SubArbol izquierdo
        build(start,mid, 2*currentNode + 1, vec);

        //SubArbol derecho
        build(mid+1, ending, 2*currentNode+2,vec);

        //Actualiza el currentNode con la suma maxima
        st[currentNode] = st[2*currentNode+1] + st[2*currentNode+2];

    }
    void build(vector<int>& vec){
        build(0,this->n-1,0,vec);
    }

    /**
     * This method returns the value of a specific range. 
     * It receives as parameters start and end of the tree, the limits of the query range ( left and right) and the node in the
     * tree in which it is.
     */
    int query(int start, int ending, int l, int r, int currentNode){
        //no hay superposicion de segmentos
        if(start>r || ending<l) return 0;

        //superposicion completa
        if(start >= l && ending<=r) return st[currentNode];

        //caso parcial
        int mid = (start+ending)/2;

        int q1 = query(start,mid, l,r,2*currentNode+1);
        int q2 = query(mid+1,ending,l,r,2*currentNode+2);
        return q1+q2;
    }

    int query(int l, int r) {
		return query(0,n-1,l,r,0);
	}

    /**
     * This method updates the segment tree. Keeping the tree updated for future queries.
     * It receives start and end of the tree, the tree node, index and value to update in the tree.
     * This updating works in o(log N) because it updates all the nodes that affect this index in the path.
     */
    void update(int start, int ending, int currentNode, int index, int val){
        //caso base
        if(start==ending){
            st[currentNode] = val;
            return;
        }
        
        int mid = (start+ending)/2;
        if(index<=mid){//el nodo se encuentra en el arbol izquierdo
            update(start,mid, 2*currentNode+1,index,val);
        }else{//el index a actualizar se encuentra en el arbol derecho
            update(mid+1,ending,2*currentNode+2,index,val);
        }

        //actualizar las sumas donde participa ese indice actualizado
        st[currentNode] = st[2*currentNode+1] + st[2*currentNode+2];

    }
    void update(int index, int val){
        update(0,n-1,0,index,val);
    }
};

int main(){

    vector<int> vec = {2,7,6,4,1,9,10,20};
    segmentTree *tree = new segmentTree;

    //CONTRUIR ARBOL
    tree->init(vec.size());
    tree->build(vec);
    
    //HACER CONSULTAS Y ACTUALIZACIONES
    cout << " query (0,0): " << tree->query(0,0) << endl;
    cout << " query (0,4): " << tree->query(0,4) << endl;
    cout << " query (5,7): " << tree->query(5,7) << endl;
    cout << " query (0,7): " << tree->query(0,7) << endl;
    cout << " query (2,5): " << tree->query(2,5) << endl;

    cout << " Update index 2 with value 100 " << endl;
    tree->update(2,100);

    cout << " query (2,5): " << tree->query(1,3) << endl;
    
    return 0;
}

/**
 * Example of how the tree looks visually.
 * [ node ] = index in the tree;
 *  Array: { 2 , 7 , 6 , 4 , 1 , 9 , 10 ,20 }
 * 
 *                          59
 *                ______  [ 0 ]  _________
 *               /                        \
 *            19                          40
 *           [ 1 ]                      [ 2 ]
 *          /     \                   /       \
 *         /       \                 /         \
 *        /         \               /           \
 *       9          10            10            30
 *     [ 3 ]       [ 4 ]         [ 5 ]         [ 6 ]
 *     /   \       /    \       /     \       /     \
 *    2     7     6      4     1       9     10     20
 *  [ 7 ] [ 8 ] [ 9 ] [ 10 ] [ 11 ] [ 12 ] [ 13 ] [ 14 ]
 * 
 * 
 */