-- =========================================
-- Create FileTable template
-- =========================================
USE StudentManage
GO

--CREATE TABLE Student(
--	Sno CHAR(9) PRIMARY KEY,
--	Sname CHAR(20) UNIQUE,
--	Ssex CHAR(2),
--	Sage SMALLINT,
--	Sdept CHAR(20),
--);
--GO

--CREATE TABLE Course
--(
--	Cno CHAR(4) PRIMARY KEY,
--	Cname CHAR(40) NOT NULL,
--	Cpno CHAR(4),
--	Ccredit SMALLINT,
--	FOREIGN KEY (Cpno) REFERENCES Course(Cno)
--);
--GO

CREATE TABLE SC
(
	Sno CHAR(9),
	Cno CHAR(4),
	Grade SMALLINT,
	PRIMARY KEY (Sno, Cno),
	FOREIGN KEY (Sno) REFERENCES Student(Sno),
	FOREIGN KEY (Cno) REFERENCES Course(Cno)
);
GO