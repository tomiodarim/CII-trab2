#ifndef VIEWTREEITEM_H
#define VIEWTREEITEM_H

#include <QTreeWidgetItem>
#include "model/model.h"

class ViewTreeItem : public QTreeWidgetItem {
public:
    ViewTreeItem(Model* model) {
       this->model = model;
    }

    Model *getModel() {
        return this->model;
    }
private:
    Model *model;

};

#endif //VIEWTREEITEM_H
