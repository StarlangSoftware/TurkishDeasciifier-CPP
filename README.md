# Deasciifier

Nlptoolkit’in bu bileşeni, Türkçe karakterler içeren metinleri Türkçe karakterlerden arındırmak veya Türkçe karakterlerden arındırılmısı bir metnin Türkçe karakterlerini geri kazandırmak için kullanılabilir. Bu araç, bir metni Türkçe karakterlerden arındırmak için oldukça basit bir yol takip etmektedir ve her bir Türkçe karakteri karşılık gelen Latince haline dönüştürmektedir. Örneğin, Ç harfleri C’ye çevrilirken, ı harfi i harfine çevrilmektedir.

Bir metne Türkçe karakterleri geri kazandırmak için ise araç iki farklı yöntem içermektedir. Bu yöntemlerin ilki basit geri dönüştürücüdür (simple deasciifier). Bu yöntem, bir kelimenin var olabilecek bütün Türkçe karakter karşılıklarını oluşturmakta ve bu seçeneklerden biçimbirimsel olarak çözümlenebilen bir tanesini rassal olarak seçip sonuç olarak sunmaktadır. Örneğin, cocuk girdisi için, basit geri dönüştürücü cocuk, çocuk, coçuk ve çoçuk seçeneklerini yaratacak ve sadece çocuk biçimbirimsel olarak çözümlenebileceği için çocuk kelimesini çıktı olarak verecektir. Diğer yöntem ise n-karakter geri dönüştürücüdür (ngram deasciifier). Bu yöntemde ise, yine her bir kelime için ilk yöntemdeki gibi bir aday listesi oluşturulur ve ardından her bir kelimenin Türkçe’deki n-karakter olasılıkları hesaplanarak en muhtemel aday çıktı olarak verilir.

For Developers
============
You can also see either [Python](https://github.com/olcaytaner/TurkishDeasciifier-Py) 
or [Java](https://github.com/olcaytaner/TurkishDeasciifier) repository.

## Requirements

* [Java Development Kit 8 or higher](#java), Open JDK or Oracle JDK
* [Maven](#maven)
* [Git](#git)

### Java 

To check if you have a compatible version of Java installed, use the following command:

    java -version
    
If you don't have a compatible version, you can download either [Oracle JDK](https://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html) or [OpenJDK](https://openjdk.java.net/install/)

### Maven
To check if you have Maven installed, use the following command:

    mvn --version
    
To install Maven, you can follow the instructions [here](https://maven.apache.org/install.html).      

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called DataStructure will be created. Or you can use below link for exploring the code:

	git clone https://github.com/olcaytaner/TurkishDeasciifier-CPP.git

## Open project with NetBeans IDE

To import projects from Git with smart import:

* Click File > Import.

* In the Import window, click Projects from Git (with smart import) and click Next.

* In the Select Repository Source window, click Existing local repository or Clone URI.

* Step through the wizard and click Finish for the wizard to analyze the content of the project folder to find projects for import and import them in the IDE. 

Result: The imported project is listed in the Project Explorer view.


## Compile

**From IDE**

After being done with the downloading and Maven indexing, select **Build Project** option from **Build** menu. After compilation process, user can run DataStructure.
