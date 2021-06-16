#include<mainwindow_filebrowser.h>
#include<QString>
#include"filestrateg.h"
#include"byfile.h"
#include"bytype.h"
#include<QMap>
#include<iostream>
void  MainWindow_FileBrowser::setPercentageStrategy(qint32 const& index){//метод для смены стратегии
    delete strat_type;

    switch (index)
    {
    case 0: //устанавливает стратегию по файлам
        strat_type = file;
        break;
    case 1://устанавливает стратегию по типам
        strat_type = type;
        break;
    }


}

QMap<QString, QPair< uint64_t,double>> MainWindow_FileBrowser::   useCalculate(QString const& path ){
     QVector<QPair<QString, uint64_t>>  file;
     file =  strat_type->calculate(path); //вычисляем размер для файлов по заданой стратегии
     QMap<QString, QPair< uint64_t,double>> filePercent;
     uint64_t Maxsize=0;
     for (int i=0; i<file.size()-1; i++ ){

          Maxsize += file[i].second;

     }
      for (int i=0; i<file.size(); i++ ){//считаем процентное соотношение
          QPair< uint64_t,double> size;

         size.first = file[i].second;
         size.second = (double(file[i].second)/double(Maxsize));
         filePercent.insert(file[i].first,size);


     }

  return filePercent;
 }
