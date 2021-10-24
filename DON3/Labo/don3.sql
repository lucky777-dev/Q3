SELECT * FROM adt.employe;
SELECT * FROM adt.departement;

-- LABO 1 & 2 : exercice 1
-- 1
SELECT * FROM adt.employe WHERE empsal > 85000;
-- 2
SELECT empno FROM adt.employe WHERE empnom LIKE '%ON%';
-- 3
SELECT COUNT(*) FROM adt.employe WHERE empsexe LIKE ('F');
-- 4
SELECT dptno,COUNT(empno) FROM adt.departement d
    JOIN adt.employe e ON d.dptno = e.empdpt 
    GROUP BY dptno;
-- 5
SELECT dptno,dptlib,AVG(empsal) FROM adt.departement d
    JOIN adt.employe e ON d.dptno = e.empdpt
    GROUP BY dptno,dptlib
    HAVING AVG(empsal) > 85000;
-- 6 : no data found
SELECT empnom FROM adt.employe
    GROUP BY empnom
    HAVING COUNT(*) > 1;
-- 7
SELECT dptadm FROM adt.departement
    GROUP BY dptadm
    HAVING COUNT(*) > 2;
-- 8
SELECT DISTINCT dptmgr FROM adt.departement;
-- 9
SELECT empnom,dptlib FROM adt.employe e
    JOIN adt.departement d ON e.empdpt = d.dptno;
-- 10
SELECT empnom FROM adt.employe e
    JOIN adt.departement d ON e.empno = d.dptmgr;
-- 11
SELECT dptno,dptlib,COUNT(empno) as nombre_employés FROM adt.departement d
    JOIN adt.employe e ON d.dptno = e.empdpt 
    GROUP BY dptno,dptlib;
-- 12 (à simplifier)
SELECT empnom FROM adt.employe
    JOIN adt.departement ON empno = dptmgr
    WHERE dptno IN (SELECT dptno FROM adt.departement 
                        JOIN adt.employe ON dptno = empdpt
                        GROUP BY dptno
                        HAVING COUNT(empno) > 5);
/*SELECT empnom FROM adt.employe 
    JOIN adt.departement ON empno = dptmgr
    AND empdpt = dptno
    GROUP BY dptno,empnom
    HAVING COUNT(empno) > 5;*/
-- 13
SELECT dptlib FROM adt.departement
    WHERE dptadm IS NOT NULL;
-- 14
SELECT empnom FROM adt.employe
    WHERE empsal >= (SELECT MAX(empsal) FROM adt.employe);
-- 15
SELECT empnom,empsal FROM adt.employe 
    WHERE empsal > (SELECT AVG(empsal) FROM adt.employe
                        WHERE empsexe = 'M')
    AND empsexe = 'F';
-- 16 (à finir)
SELECT dptlib FROM adt.departement d
    JOIN adt.employe e ON d.dptno = e.empdpt
    GROUP BY dptlib
    HAVING COUNT(empno) >= (SELECT COUNT(empno) FROM adt.employe emp
                                WHERE emp.empdpt = d.dptno);
-- ==================================================================================
-- Labo 3 : jointures externes
-- Exercice 1:
-- 1
SELECT d.dptlib administré, dt.dptlib administrant FROM adt.departement d 
    LEFT OUTER JOIN adt.departement dt
    ON d.dptadm = dt.dptno
    ORDER BY dt.dptlib;
-- 2    
SELECT dp.dptlib dpt_pas_administrant FROM adt.departement d 
    RIGHT OUTER JOIN adt.departement dp
    ON d.dptadm = dp.dptno
    WHERE d.dptno IS NULL;
-- 3
SELECT d.dptlib,COUNT(dp.dptadm) nb_dpt_administré FROM adt.departement d
    LEFT OUTER JOIN adt.departement dp
    ON d.dptno = dp.dptadm
    GROUP BY d.dptlib;
-- 4 (à finir)
SELECT dptlib,dptmgr,COUNT(empno) nb_employés FROM adt.departement
    JOIN adt.employe ON dptno = empdpt
    GROUP BY dptlib,dptmgr;
-- Les dpt et leur nb d'employés
SELECT dptlib,COUNT(empno) nb_employés FROM adt.departement
    JOIN adt.employe ON dptno = empdpt
    GROUP BY dptlib;
-- Les managers et leur département qu'ils dirigent
SELECT dptlib,empnom FROM adt.employe JOIN adt.departement ON empno = dptmgr;

        
        
        
        
        
        
        
        
        