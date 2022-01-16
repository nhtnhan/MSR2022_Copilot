# An Empirical Evaluation of GitHub Copilot’s Code Suggestions
This is an artfiact for the MSR 2022 submission titled "An Empirical Evaluation of GitHub Copilot’s Code Suggestions".
The artifact contains an archived version of the first code solution suggested by Github Copilot, the LeetCode submission JSON files, and the Python scripts we use to answer RQ1 and RQ2.  




Prequisites 
------------
- Leetcode account (all Leetcode related was done through this account: [663_copilot](https://leetcode.com/663_copilot/))
- SonarQube (refer to SonarQube's [installation guide](https://docs.sonarqube.org/latest/setup/get-started-2-minutes/)) 
- Python 3
- Access to Github Copilot (at this time, github copilot is still under technical preview, you can join the waitlist [here](https://github.com/features/copilot/signup))  

Instructions 
------------

The post-processed data from Github Copilot and LeetCode can be found in [output/copilot](output/copilot) and [output/leetcode](output/leetcode) respectively. 

To answer RQ1:
- run `python3 src/get_stat.py` to get overall data summary
- Table 1 in the paper corresponds to [correctness.csv](output/questions_data/correctness.csv). The file contains names of the 33 questions, total number of test cases for each question, and the number of passed test cases for Python, Java, JavaScript codes when running against the test cases of each question. RE stands for Runtime Error; CE stands for Compile Error
  
To answer RQ2:
- in SonarQube's dashboard, create 3 projects manually for each of the following directories and follow SonarQube's guide to run analysis on each of these directories to get the Cognitive and Cylcomatic Complexity for each language:
    * for Java: [output/sonar_java](output/sonar_java/)
    * for Python: [output/copilot/python](output/copilot/python)
    * for Javascript: [output/copilot/javascript](output/copilot/javascript)
- Figure 3 in the paper corresponds to the data in [complexity.csv](output/questions_data/complexity.csv). The file contains names of the 33 questions, cognitive and cyclomatic complexity of the Python, Java, and Javascript codes for each of the 33 questions 
