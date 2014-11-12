#include "nurbs.h"

#include "function.h"

Nurbs::Nurbs(bool isNominal, QObject *parent) : Geometry(isNominal, parent)
{
    this->id = Configuration::generateID();
    this->myNominalCoordSys = NULL;
    this->isSolved = false;
    this->isUpdated = false;
    this->isDrawn = true;
}

/*!
 * \brief Nurbs::Nurbs
 * \param copy
 */
Nurbs::Nurbs(const Nurbs &copy) : Geometry(copy.isNominal){
    this->id = copy.id;
    this->name = copy.name;
    this->isSolved = copy.isSolved;
}

void Nurbs::recalc(){

    if(this->functionList.size() > 0){

        bool solved = true;
        foreach(Function *f, this->functionList){

            //execute the function if it exists and if the last function was executed successfully
            if(f != NULL && solved == true){
                solved = f->exec(*this);
            }

        }
        this->setIsSolved(solved);

    }else if(this->isNominal == false){

        this->setIsSolved(false);

    }
}

/*!
 * \brief Nurbs::toOpenIndyXML
 * \param xmlDoc
 * \return
 */
QDomElement Nurbs::toOpenIndyXML(QDomDocument &xmlDoc) const{

    QDomElement nurbs = Geometry::toOpenIndyXML(xmlDoc);

    if(nurbs.isNull()){
        return nurbs;
    }

    nurbs.setAttribute("type", Configuration::sNurbs);

    return nurbs;

}

/*!
 * \brief Nurbs::fromOpenIndyXML
 * \param xmlElem
 * \return
 */
bool Nurbs::fromOpenIndyXML(QDomElement &xmlElem){

    bool result = Geometry::fromOpenIndyXML(xmlElem);

    if(result){



    }

    return result;

}

bool Nurbs::saveSimulationData()
{
    return false;
}
