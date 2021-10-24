select * from user_tables;
SELECT * FROM Test;
-- 1. Création de table
-- ===================
-- 1
CREATE TABLE Test (
    tId int NOT NULL,
    tLib varchar(50) NOT NULL,
    --(5,2) voir doc Orcale -> Number data type
    -- 5 digit significatif au total, 2 digit derrière la virgule et 3 devant.
    tNb1 decimal(5,2) DEFAULT 12 NOT NULL,
    tNb2 decimal(8,2) NOT NULL);
    
-- 2
INSERT INTO Test 
    VALUES (01,'abc',123.45,123456.78);
INSERT INTO Test 
    VALUES (02,'def',66.89,1111.1);
INSERT INTO Test 
    VALUES (03,'ghi',7.77,56.78);
-- Cette commande ne fonctionne pas puisque attribut tLib obligatoire !
INSERT INTO Test (tId,tNb1,tNb2) 
    VALUES (03,7.77,56.78);

-- 3
INSERT INTO Test 
    VALUES (04,'jkl',2,598);
INSERT INTO Test 
    VALUES (04,'mno',59.1,128.69);

-- 4
INSERT INTO Test (tId,tLib,tNb2)
    VALUES (3220,'Rust',14.90);
    
-- 2. Ajout de contraintes
-- =======================
/*UPDATE Test
    SET tNb2 = 12.1
    WHERE tNb2 = 10.9;
UPDATE Test
    SET tId = 2959
    WHERE tLib = 'mno';*/
-- ==> j'ai du mettre à jour certains tuples pour que ajouter les contraintes    
-- 1 
ALTER TABLE Test 
    ADD CONSTRAINT tNb1CHK CHECK (tNb1 > 0);
ALTER TABLE Test 
    ADD CONSTRAINT tNb2CHK CHECK (tNb2 > tNb1);
ALTER TABLE Test 
    ADD CONSTRAINT Nb1Nb2UK UNIQUE(tNb1,tNb2);
ALTER TABLE Test 
    ADD CONSTRAINT TestPK PRIMARY KEY(tId);
    
-- 2
UPDATE Test
    SET tId = 2959
    WHERE tId = 4;
UPDATE Test
    SET tNb1 = -1.22
    WHERE tLib = 'Rust';
UPDATE Test
    SET tNb1 = 12, tNb2 = 12.1
    WHERE tLib = 'def';
UPDATE Test
    SET tNb1 = 19.22, tNb2 = 13.25
    WHERE tLib = 'abc';

-- 3
CREATE TABLE Test2 (
    ttId int,
    t2Ref int);
-- 4
ALTER TABLE Test2
    ADD CONSTRAINT FK_t2Ref FOREIGN KEY (t2Ref)
        REFERENCES Test(tId);
-- 5
INSERT INTO Test2
    VALUES('007','3220');
INSERT INTO Test2
    VALUES('003','2959');
-- 6
-- Violation de contrainte -> fils existant
DELETE FROM Test
    WHERE tId = '3220';
ALTER TABLE Test2
    DROP CONSTRAINT FK_t2Ref;
ALTER TABLE Test2
    ADD CONSTRAINT FK_t2Ref FOREIGN KEY (t2Ref)
        REFERENCES Test(tId)
        ON DELETE CASCADE;
-- Maintenant ça marche
DELETE FROM Test
    WHERE tId = '3220';

-- 7
ALTER TABLE Test2
    DROP CONSTRAINT FK_t2Ref;
ALTER TABLE Test2
    ADD CONSTRAINT FK_t2Ref FOREIGN KEY (t2Ref)
        REFERENCES Test(tId)
        DEFERRABLE INITIALLY DEFERRED;
DELETE FROM Test
    WHERE tId = '3220';

