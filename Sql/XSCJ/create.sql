--1
--CREATE DATABASE XSCJ
--ON
--(
--	NAME='XSCJ_Data',
--	FILENAME='D:\Program Files (x86)\Microsoft SQL Server\SQL Server Manage\XSCJ\Data\XSCJ.mdf',
--	SIZE=5MB,
--	FILEGROWTH=10%
--)
--LOG ON
--(
--	NAME='XSCJ_Log',
--   		FILENAME='D:\Program Files (x86)\Microsoft SQL Server\SQL Server Manage\XSCJ\Data\XSCJ_Log.ldf',
--   		SIZE=2MB,
--   		MAXSIZE=5MB,
--   		FILEGROWTH=1MB
--);
--GO


--2
--CREATE TABLE Course
--(
--	Cno CHAR(4) PRIMARY KEY,
--	Cname CHAR(40) not null,
--	Cpno CHAR(4),
--	Ccredit SMALLINT,
--	FOREIGN KEY (Cpno) REFERENCES Course(Cno)
--);





--3
--ALTER TABLE Course ADD term CHAR(2)
























--4
--CREATE UNIQUE INDEX Cname_idx ON Course(Cname);






















--5
--DROP INDEX Cname_idx ON Course;























--6
--CREATE TABLE Student
--(
--	Sno CHAR(4) PRIMARY KEY,
--	Sname CHAR(40)
--);









--DROP TABLE Student











--7
--DROP DATABASE XSCJ












--拓展练习
--1
--CREATE DATABASE BSXT
--ON
--(
--	NAME='BSXT_Data',
--	FILENAME='D:\Program Files (x86)\Microsoft SQL Server\SQL Server Manage\BSXT\Data\BSXT.mdf',
--	SIZE=5MB,
--	FILEGROWTH=10%
--)
--LOG ON
--(
--	NAME='BSXT_Log',
--   		FILENAME='D:\Program Files (x86)\Microsoft SQL Server\SQL Server Manage\BSXT\Data\BSXT_Log.ldf',
--   		SIZE=2MB,
--   		MAXSIZE=5MB,
--   		FILEGROWTH=1MB
--);
--GO







--2
--ALTER DATABASE BSXT
--MODIFY FILE
--(
--	NAME = BSXT_Data,
--	MAXSIZE = Unlimited
--)








--3
--CREATE TABLE Student
--	(
--		Sno CHAR(10) NOT NULL PRIMARY KEY,
--		Sname CHAR(10) NOT NULL,
--		Ssex CHAR(2) CHECK(Ssex='男' or Ssex='女'),
--		Sclass CHAR(10),
--		Stel CHAR(11) NOT NULL,
--		Sgroup CHAR(1) NOT NULL,
--		Spassword CHAR(10) NOT NULL
--	);


--CREATE TABLE Teacher
--	(
--		Tno CHAR(10) NOT NULL PRIMARY KEY,
--		Tname CHAR(10) NOT NULL UNIQUE,
--		Tsex char(2),
--		Tdept CHAR(20) NOT NULL DEFAULT '计算机科学与技术系',
--		Tdegree CHAR(8),
--		Ttitle CHAR(4),
--		Tright bit not null,
--		Ttel char(11) not null,
--		Temail char(50),
--		Troup char(1) not null,
--		Tpassword char(10) not null
--	);

--create table Topic
--	(
--		Hno char(4) not null primary key,
--		Hname char(50) not null,
--		Hstatus char(5) not null,
--		Hcontent char(200),
--		dircetion char(200),
--		Tno char(10),
--		Sno char(10),
--		foreign key (Tno) references Teacher(Tno),
--		foreign key (Sno) references Student(Sno)
--	);







--实验二

--创建Student表
--create table Student
--(
--	Sno char(9) primary key,
--	Sname char(20) unique,
--	Ssex char(2),
--	Sdept char(20)
--);


--CREATE TABLE Course
--(
--	Cno CHAR(4) PRIMARY KEY,
--	Cname CHAR(40) not null,
--	Cpno CHAR(4),
--	Ccredit SMALLINT,
--	FOREIGN KEY (Cpno) REFERENCES Course(Cno)
--);


--创建SC表
--create table SC
--(
--	Sno char(9),
--	Cno char(4),
--	Grade smallint,
--	primary key (Sno, Cno),
--	foreign key (Sno) references Student(Sno),
--	foreign key (Cno) references Course(Cno)
--)


--alter table Student add Sage smallint


--select distinct Sno
--	from SC;

--select  Sname  XM , 2020-Sage  CSNF
--FROM Student;

--SELECT Sno, Sname,Sdept
--FROM     Student
--WHERE   Sage BETWEEN 20 AND 23;


--SELECT Sname,Ssex
--	FROM  Student
--	WHERE Sdept IN ( 'IS','MA','CS' );


--SELECT Cno,Ccredit
--      FROM Course
--      WHERE Cname LIKE 'DB\_S' ESCAPE '\';


--SELECT Sno,Cno
--    FROM  SC
--    WHERE  Grade IS NOT NULL;

--SELECT  *
--        FROM  Student
--        ORDER BY Sdept,Sage DESC;  

--SELECT COUNT(DISTINCT Sno)
--    FROM SC;


--SELECT AVG(Grade)
--    FROM SC
--    WHERE Cno= '1';


--SELECT Sno
--     FROM  SC
--     GROUP BY Sno
--     HAVING  COUNT(*) >3;  


--SELECT  FIRST.Cno,SECOND.Cpno
--       FROM  Course  FIRST,Course  SECOND
--      WHERE FIRST.Cpno = SECOND.Cno and FIRST.Cpno='1'



--SELECT Student.Sno,Sname,Ssex,Sage,Sdept,Cno,Grade
--    FROM  Student  LEFT OUTER JOIN SC ON (Student.Sno=SC.Sno);


--SELECT Sno, Cno
--    FROM  SC  x
--    WHERE Grade >=(SELECT AVG(Grade) 
--		                        FROM  SC y
--                                   WHERE y.Sno=x.Sno);



--select Sno, Sname, Stel
--	from Student;


--select *
--from Student;


--select distinct Tno
--from Topic;

--select *
--from Teacher
--where Tname = '朱龙';

--select *
--from Student
--where Sname like '王%';


--select Tdegree, count(*) as number
--from Teacher
--group by Tdegree;


--select Student.Sno, Sname, Teacher.Tno, Tname, Hname
--from Student left outer join topic on(Student.Sno=Topic.Sno), Teacher
--where Teacher.Troup='1' and Student.Sgroup=Teacher.Troup and Teacher.Tno=Topic.Tno

--select Student.Sno, Sname, Hname, Tname
--from Student left outer join (select Hname, Tname, Sno, Troup
--from Topic, Teacher
--where Topic.Tno=Teacher.Tno) temp on (Student.Sno=TEMP.Sno)



--实验三
--insert
--into Student
--values ('95007', '张娜丽', '女', 'IS', 18)


--INSERT
--    INTO SC(Sno, Cno)
--    VALUES ('95007', '1');


--create table Dept_age
--(
--	Sdept char(15),
--	Avg_age smallint
--);
--insert 
--	into Dept_age(Sdept, Avg_age)
--	select Sdept, AVG(Sage)
--	from Student
--	group by Sdept;

--update Student
--	set Sage=Sage+1;


update SC
	set Grade=0
	where 'IS'=(
		select Sdept
		from Student
		where Student.Sno = SC.Sno
	)


--delete from Student where Sno='95001';



--DELETE
--        FROM SC
--        WHERE  'CS'=(selete Sdept
--                    FROM Student
--                    WHERE Student.Sno=SC.Sno);


--create view CS_S
--as
--select Sno, Sname, Sage, Sdept
--from Student
--where Sdept='CS'
--with check option;


--insert into CS_S values('95003', '王冬冬', '20', 'CS')


--select Sno, Sage
--from CS_S
--where Sage<20


--select Sno, Sname
--from CS_S
--where Sno='2'


--拓展练习
--insert into Topic(Hno, Hname, Hstatus, Tno, Sno)
--values('H06', '学生成绩管理系统', '已选', 'T03', '0706034107')


--update Teacher
--	set Tdegree = '博士' where Tname='李霞'



--delete 
--from Topic
--where Topic.Sno in
--		(
--			select Student.Sno
--			from Student
--			where Sgroup='1'
--		)


--create view Condition
--as 
--select Student.Sno, Sname, Tname, Hname, Ttel
--from Student, Topic, Teacher
--where Topic.Sno=Student.Sno and Topic.Tno=Teacher.Tno
--with check option


--select Sno, Sname, Hname
--from Condition
--where Tname='杨坚'



--实验四

--create login U1 with password='123456'
--create login U2 with password='123456'





--grant select
--on Student
--to U1
--with grant option




--grant select
--on Student
--to U2



--revoke select
--on Student
--from U1
--cascade