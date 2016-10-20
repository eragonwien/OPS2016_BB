OPS 2016 BB

STATUS CHECK
git status
*********************

BASIC ADD FILE
git add
git commit -m "sdfsfsfsa"
git push origin master
*********************

BASIC UPDATE FILE
git pull


*********************
MERGE FILE (Advanced)

	MERGE TEST TO MASTER
	git checkout master
	git pull
	git checkout test
	git merge origin/test 
	
	APPLY ON MASTER
	git checkout master
	git merge test
	git push