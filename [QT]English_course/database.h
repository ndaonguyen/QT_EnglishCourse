#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase> 
#include <QtGui/QMessageBox>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/qsqldriver.h>
#include <QtSql/QSqlDriverPlugin>

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <C:\wamp32\bin\mysql\mysql5.5.16\include\mysql.h>

using namespace std;




class database
{
public:
	static bool createConnection()
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("127.0.0.1");
		db.setDatabaseName("qt_tracking");
		db.setUserName("root");
		db.setPassword("");
		if (!db.open()) {
		    QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
			return false;
		}
		return true;
	}

	static MYSQL* connectByC()
	{
	
		MYSQL *con = mysql_init(NULL);
		if(mysql_real_connect(con, "127.0.0.1","root","","qt_tracking",0,NULL,0)== NULL)
		{
			mysql_error(con);
			return NULL;
		}
		else
		{
			return con;
		}		
	}

	static void closeConnectionC(MYSQL *connect)
	{
		mysql_close(connect);
	}

	// MATERIAL TABLE
	static MYSQL_ROW material_searchMaterialId(MYSQL *connect, int materialId)
	{
	/**
	** @parameter : skillID	
	** @return:  row of all value from skill table
	*/
		MYSQL_RES *res_set;
		MYSQL_ROW row;
		char bufferId[5];
		itoa(materialId,bufferId,10);

		QString tem = "SELECT * FROM `english_course`.`material` WHERE `id` = '"+QString::fromUtf8(bufferId)+"'";			
		std::string temp1 = tem.toStdString();
		const char* temp2 = temp1.c_str();
		if(mysql_query(connect,temp2) ==0)
		{
			res_set = mysql_store_result(connect);
			row = mysql_fetch_row(res_set);
			return row;
		}
		return NULL;

	}

	static int material_getMaxId(MYSQL *connect)
	{
	/**
	**	@return: max id from material table
	*/
		QString query = "SELECT MAX(id) FROM `english_course`.`material`";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			MYSQL_RES *res_set;
			MYSQL_ROW row;

			res_set = mysql_store_result(connect);
			row     = mysql_fetch_row(res_set);
			return atoi(row[0]);
		}
		return -1;
	}

	static int material_saveAction(MYSQL *connect,QString materialName)
	{
	/**
	** @parameter : material name 	
	** @return: id inserted
	*/
		QString query = "INSERT INTO `english_course`.`material` VALUES(NULL,'"+materialName+"')";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			return material_getMaxId(connect);
		}
		return -1;
	}

	//SKILL TABLE
	static MYSQL_ROW skill_searchSkillId(MYSQL *connect, int skillId)
	{
	/**
	** @parameter : skillID	
	** @return:  row of all value from skill table
	*/
		MYSQL_RES *res_set;
		MYSQL_ROW row;
		char bufferId[5];
		itoa(skillId,bufferId,10);


		QString tem = "SELECT * FROM `english_course`.`skill` WHERE `id` = '"+QString::fromUtf8(bufferId)+"'";			
		std::string temp1 = tem.toStdString();
		const char* temp2 = temp1.c_str();
		if(mysql_query(connect,temp2) ==0)
		{
			res_set = mysql_store_result(connect);
			row = mysql_fetch_row(res_set);
			return row;
		}
		return NULL;
	}

	static int skill_saveAction(MYSQL *connect, QString skillName)
	{
	/**
	** @parameter : material name 	
	** @return: id inserted
	*/
		QString query = "INSERT INTO `english_course`.`skill` VALUES(NULL,'"+skillName+"')";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			return skill_getMaxId(connect);
		}
		return -1;
	}

	static int skill_getMaxId(MYSQL *connect)
	{
		QString query = "SELECT MAX(id) FROM `english_course`.`skill`";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			MYSQL_RES *res_set;
			MYSQL_ROW row;

			res_set = mysql_store_result(connect);
			row     = mysql_fetch_row(res_set);
			return atoi(row[0]);
		}
		return -1;
	}

	static MYSQL_ROW skill_searchName(MYSQL *connect, QString skillName)
	{
		/**
		** @parameter: skill name
		** @return : row of all value from skill table
		*/
		MYSQL_RES *res_set;
		MYSQL_ROW row;

		QString tem = "SELECT * FROM `english_course`.`skill` WHERE `name` = '"+skillName+"'";			
		std::string temp1 = tem.toStdString();
		const char* temp2 = temp1.c_str();
		if(mysql_query(connect,temp2) ==0)
		{
			res_set = mysql_store_result(connect);
			row = mysql_fetch_row(res_set);
			return row;
		}
		return NULL;
	}

	//SKILL_MATERIAL table
	static int skillMaterial_getMaxMaterialID(MYSQL *connect)
	{
		QString query = "SELECT MAX(material_id) FROM `english_course`.`skill_material`";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			MYSQL_RES *res_set;
			MYSQL_ROW row;

			res_set = mysql_store_result(connect);
			row     = mysql_fetch_row(res_set);
			return atoi(row[0]);
		}
		return -1;
	}

	static MYSQL_RES* skillMaterial_searchSkillId(MYSQL *connect, int skillId)
	{
		/**
		** @parameter: skill id
		** @return : row of all value 
		*/
		MYSQL_RES *res_set;
//		MYSQL_ROW *row ;
		char bufferId[5];
		itoa(skillId,bufferId,10);

		QString tem = "SELECT * FROM `english_course`.`skill_material` WHERE `skill_id` = '"+QString::fromUtf8(bufferId)+"'";			
		std::string temp1 = tem.toStdString();
		const char* temp2 = temp1.c_str();
		if(mysql_query(connect,temp2) ==0)
		{
			res_set = mysql_store_result(connect);
		//	row = mysql_fetch_row(res_set);
			return res_set;
		}
		return NULL;
	}

	static int skillMaterial_saveAction(MYSQL *connect,int idSkill, int idMaterial, int idCourse)
	{
	/**
	** @parameter : material name 	
	** @return: id inserted
	*/
		char skill[5];
		char material[5];
		char course[5];
		itoa(idSkill,skill,10);
		itoa(idMaterial,material,10);
		itoa(idCourse,course,10);

		QString query = "INSERT INTO `english_course`.`skill_material` VALUE("+QString::fromUtf8(skill)+","+QString::fromUtf8(material)+","+QString::fromUtf8(course)+")";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			return skillMaterial_getMaxMaterialID(connect);
		}
		return -1;
	}

	//COURSE table
	static int course_saveAction(MYSQL *connect, QString courseName)
	{
	/**
	** @parameter : material name 	
	** @return: id inserted
	*/
		QString query = "INSERT INTO `english_course`.`course` VALUES(NULL,'"+courseName+"')";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			return course_getMaxId(connect);
		}
		return -1;
	}
	static int course_getMaxId(MYSQL *connect)
	{
		QString query = "SELECT MAX(id) FROM `english_course`.`course`";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			MYSQL_RES *res_set;
			MYSQL_ROW row;

			res_set = mysql_store_result(connect);
			row     = mysql_fetch_row(res_set);
			return atoi(row[0]);
		}
		return -1;
	}
	static MYSQL_ROW course_searchName(MYSQL *connect, QString courseName)
	{
		/**
		** @parameter: skill name
		** @return : row of all value from skill table
		*/
		MYSQL_RES *res_set;
		MYSQL_ROW row;

		QString tem = "SELECT * FROM `english_course`.`course` WHERE `name` = '"+courseName+"'";			
		std::string temp1 = tem.toStdString();
		const char* temp2 = temp1.c_str();
		if(mysql_query(connect,temp2) ==0)
		{
			res_set = mysql_store_result(connect);
			row = mysql_fetch_row(res_set);
			return row;
		}
		return NULL;
	}


	// COURSE_SKILL table
	static int courseSkill_saveAction(MYSQL *connect,int idSkill, int idCourse)
	{
	/**
	** @parameter : material name 	
	** @return: id inserted
	*/
		char skill[5];
		char course[5];
		itoa(idSkill,skill,10);
		itoa(idCourse,course,10);

		QString query = "INSERT INTO `english_course`.`course_skill` VALUE("+QString::fromUtf8(course)+","+QString::fromUtf8(skill)+")";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			return skillMaterial_getMaxSkillID(connect);
		}
		return -1;
	}
	static int skillMaterial_getMaxSkillID(MYSQL *connect)
	{
		QString query = "SELECT MAX(skill_id) FROM `english_course`.`course_skill`";
		std::string query2 = query.toStdString();
		const char* query1 = query2.c_str();
		if(mysql_query(connect,query1)==0)
		{
			MYSQL_RES *res_set;
			MYSQL_ROW row;

			res_set = mysql_store_result(connect);
			row     = mysql_fetch_row(res_set);
			return atoi(row[0]);
		}
		return -1;
	}
};



#endif