       #ifndef _TREE_H_
        #define _TREE_H_
        template <class Comparable>
        class BinarySearchTree;

        template <class Comparable>
        class BinaryNode
        {
          public:
              Comparable word;
              Comparable mean;
              BinaryNode  *left;
              BinaryNode  *right;

              BinaryNode( const Comparable & theWord,const Comparable & theMean, BinaryNode *lt, BinaryNode *rt ) : word( theWord ),mean(theMean), left( lt ), right( rt ) { }
              friend class BinarySearchTree<Comparable>;
        };

       template <class Comparable>
        class BinarySearchTree
        {
           public:
              explicit BinarySearchTree( const Comparable & notFound );
             BinarySearchTree(): root(nullptr) {}
             
              BinarySearchTree( const BinarySearchTree & rhs );
              ~BinarySearchTree( );

              BinaryNode<Comparable> * find( const Comparable & x, BinaryNode<Comparable> *t ) const;
              bool isEmpty( ) const;
              void makeEmpty( BinaryNode<Comparable> * & t ) const;
              void insert( const Comparable & w,const Comparable & m, BinaryNode<Comparable> * & t ) const;
              // void remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
              //const BinarySearchTree & operator=( const BinarySearchTree & rhs );

              // private:
            BinaryNode<Comparable> *root;
            const Comparable ITEM_NOT_FOUND;

            const Comparable & wordAt( BinaryNode<Comparable> *t ) const;
            const Comparable & meanAt( BinaryNode<Comparable> *t ) const;

            //BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;
        };
        
template <class Comparable> //Construct the tree.
        BinarySearchTree<Comparable>::BinarySearchTree(const Comparable & notFound ) :ITEM_NOT_FOUND( notFound ), root( NULL ) {}
    
template <class Comparable> //method to get element field in node t.
        const Comparable & BinarySearchTree<Comparable>::wordAt( BinaryNode<Comparable> *t ) const
        {
            return t == NULL ? ITEM_NOT_FOUND : t->word;
        }

 template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::meanAt( BinaryNode<Comparable> *t ) const
        {
            return t == NULL ? ITEM_NOT_FOUND : t->mean;
        }

template <class Comparable> //method to find an item in a subtree. //x is item to search for. t is the node to return
        BinaryNode<Comparable> *BinarySearchTree<Comparable>::find( const Comparable & x, BinaryNode<Comparable> * t ) const
        {
             if ( t == NULL )
                  return NULL;
             else if( x < t->word )
                  return find( x, t->left );
             else if( t->word < x )
                  return find( x, t->right );
             else
                  return t;    // Match
        }
 template <class Comparable> //method to insert into a subtree.x is the item.t is the node that root
        void BinarySearchTree<Comparable>::insert( const Comparable & w,const Comparable & m, BinaryNode<Comparable> * & t ) const
        {
            if( t == NULL ) //  create a new node at the right place
                t = new BinaryNode<Comparable>( w,m, NULL, NULL );
            else if( w < t->word )
                insert( w,m, t->left );  // insert at the left or 
            else if( t->word < w )
                insert( w,m, t->right );  // right subtree
            else
                ;  // Duplicate; do nothing
        }
template <class Comparable> //method to make subtree empty.
        void BinarySearchTree<Comparable>::makeEmpty( BinaryNode<Comparable> * & t ) const
        {
            if( t != NULL )
            {
                makeEmpty( t->left );
                makeEmpty( t->right );
                delete t;
            }
            t = NULL;
        }
template <class Comparable> //destructor
        BinarySearchTree<Comparable>::~BinarySearchTree( )
        {
            makeEmpty(this->root );
        }
template <class Comparable> //Copy constructor.
        BinarySearchTree<Comparable>::BinarySearchTree( const BinarySearchTree<Comparable> & rhs ) :
              root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
        { 
            *this = rhs;
        }

#endif






       /**
         * Internal method to remove from a subtree.
         * x is the item to remove.
         * t is the node that roots the tree.
         * Set the new root.
         
        template <class Comparable>
        void BinarySearchTree<Comparable>::remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
        {
            if( t == NULL )
                return;   // Item not found; do nothing
            if( x < t->word )
                remove( x, t->left );
            else if( t->word < x )
                remove( x, t->right );
                        
            else if( t->left != NULL && t->right != NULL ) // Two children
            {
                t->element = findMin( t->right )->element;
                remove( t->element, t->right );
            }
            else // one or no children
            {
                BinaryNode<Comparable> *oldNode = t;
                t = ( t->left != NULL ) ? t->left : t->right;
                delete oldNode;
            }
        } 
*/