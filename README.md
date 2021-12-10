# CMPUT663-copilot-eval
The artifact is an archived of first code suggested by Github Copilot, LeetCode submission JSON files, python scripts to answer RQ1 and RQ2.  

Prequisites outlines tools required for me to run the study. However, post-processed data from Github Copilot and LeetCode can be found in [output/copilot](output/copilot) and [output/leetcode](output/leetcode) respectively. 

Project Report 
------------
Title: Evaluating Code Converted from Comments by GitHub Copilot  

Prequisites 
------------
- Leetcode account (all Leetcode related was done through this account: [663_copilot](https://leetcode.com/663_copilot/))
- SonarQube (to answer RQ2) 
- Python 3
- Access to Github Copilot (at this time, github copilot is still under technical preview, you can join the waitlist [here](https://github.com/features/copilot/signup))  

Instructions 
------------
To answer RQ1, use the following command in the current directory  
- `python3 src/get_stat.py`
  
To answer RQ2, run SonarQube on each of these directories to get the Cognitive and Cylcomatic Complexity for each language:
- for Java: [output/sonar_java](output/sonar_java/)
- for Python: [output/copilot/python](output/copilot/python)
- for Javascript: [output/copilot/javascript](output/copilot/javascript)
