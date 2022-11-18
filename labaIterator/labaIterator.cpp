#include <iostream>
#include <fstream>
#include "SeqList.h"
#include "SeqListIterator.h"

using namespace std;

struct SalesPerson {
    int idno;
    int units;
};

int operator == (const SalesPerson& a, const SalesPerson& b) {
    return a.idno == b.idno;
}

void printTotalSales(SeqList<SalesPerson>& l, int id) {
    SalesPerson salesP{ id,0 };
    SeqListIterator<SalesPerson> iter(l);
    for (iter.reset(); !iter.endOfList(); iter.next())
        if (iter.data() == salesP)
            salesP.units += (iter.data()).units;
    cout << "Служащий: " << salesP.idno
        << " Количество проданного товара: " << salesP.units << endl;
}


int main()
{
    setlocale(0, "ru");
    SeqList<SalesPerson> salesList;
    SeqList<int> idList;
    ifstream salesFile;
    SalesPerson salesP;
    salesFile.open("sales.dat", ios::in| ios::_Nocreate);
    if (!salesFile) {
        cerr << "Файле sales.dat не найден!";
        exit(1);
    }
    while (!salesFile.eof()) {
        salesFile >> salesP.idno >> salesP.units;
        salesList.insertItem(salesP);
        if (!idList.find(salesP.idno))
            idList.insertItem(salesP.idno);
    }
    SeqListIterator<int> idIter(idList);
    for (idIter.reset(); !idIter.endOfList(); idIter.next())
        printTotalSales(salesList, idIter.data());
}
