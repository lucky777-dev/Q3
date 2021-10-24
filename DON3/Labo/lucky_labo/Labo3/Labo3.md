# Labo 3

## 1

```sql
SELECT d1.dptlib, d2.dptadm
 FROM gcuv.departement d1
    LEFT JOIN gcuv.departement d2 on d1.dptno = d2.dptadm;
```

## 2

```sql
SELECT d1.dptno 
 FROM gcuv.departement d1
EXCEPT /* MINUS */
SELECT d1.dptno
 FROM gcuv.departement d1
    RIGHT JOIN gcuv.departement d2 ON d1.dptno = d2.dptadm;
```

# 3

```sql
SELECT d1.dtplib, count()
```