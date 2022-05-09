#include "collection.h"

Collection::Collection(QObject *parent) : QObject(parent)
{

}


void Collection::sort ( QList<Model*> &lm ) {
    for ( int i=0; i<lm.count()-1; i++ ) {
        for ( int j=i+1; j<lm.count(); j++ ) {
            if (lm.at(i)->compareTo(lm.at(j))>0) {
                lm.swapItemsAt(i,j);
            }
        }
    }
}
