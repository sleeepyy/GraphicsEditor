#include "app.h"
#include "common.h"
#include "view.h"
#include "model.h"
#include "viewmodel.h"

App::App():
m(new Model), vm(new ViewModel), v(new View)
{

}

App::~App(){
    delete model;
    delete viewmodel;
    delete view;
}
