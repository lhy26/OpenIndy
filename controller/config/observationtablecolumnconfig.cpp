#include "observationtablecolumnconfig.h"

/*!
 * \brief ObservationTableColumnConfig::ObservationTableColumnConfig
 */
ObservationTableColumnConfig::ObservationTableColumnConfig(){

    //load default column config
    this->init();

}

/*!
 * \brief ObservationTableColumnConfig::getColumnVisibility
 * \param column
 * \return
 */
bool ObservationTableColumnConfig::getColumnVisibility(const ObservationDisplayattributes &column) const{
    return this->displayColumns.contains(column);
}

/*!
 * \brief ObservationTableColumnConfig::setColumnVisibility
 * \param column
 * \param isVisible
 */
void ObservationTableColumnConfig::setColumnVisibility(const ObservationDisplayattributes &column, const bool &isVisible){
    if(isVisible && !this->displayColumns.contains(column)){
        this->displayColumns.append(column);
    }else{
        this->displayColumns.removeOne(column);
    }
}

/*!
 * \brief ObservationTableColumnConfig::getColumnPosition
 * Returns the position index of the given column or -1 if the column is not displayed
 * \param column
 * \return
 */
int ObservationTableColumnConfig::getColumnPosition(const ObservationDisplayattributes &column) const{
    return this->displayColumns.indexOf(column);
}

/*!
 * \brief ObservationTableColumnConfig::setColumnPosition
 * \param column
 * \param index
 */
void ObservationTableColumnConfig::setColumnPosition(const ObservationDisplayattributes &column, const int &index){
    if(this->displayColumns.contains(column) && index >= 0 && index < this->displayColumns.size()){
        this->displayColumns.removeOne(column);
        this->displayColumns.insert(index, column);
    }
}

/*!
 * \brief ObservationTableColumnConfig::init
 * Set up default column config
 */
void ObservationTableColumnConfig::init(){

    //default columns in default order
    this->displayColumns.append(eObservationDisplayId);
    this->displayColumns.append(eObservationDisplayStation);
    this->displayColumns.append(eObservationDisplayTargetGeometries);
    this->displayColumns.append(eObservationDisplayX);
    this->displayColumns.append(eObservationDisplayY);
    this->displayColumns.append(eObservationDisplayZ);
    this->displayColumns.append(eObservationDisplaySigmaX);
    this->displayColumns.append(eObservationDisplaySigmaY);
    this->displayColumns.append(eObservationDisplaySigmaZ);
    this->displayColumns.append(eObservationDisplayIsValid);
    this->displayColumns.append(eObservationDisplayIsSolved);

}
