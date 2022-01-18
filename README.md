# An Empirical Evaluation of GitHub Copilot’s Code Suggestions
This is an artfiact for the MSR 2022 submission titled "An Empirical Evaluation of GitHub Copilot’s Code Suggestions".
The artifact contains an archived version of the first code solution suggested by Github Copilot, the LeetCode submission JSON files, and the Python scripts we use to answer RQ1 and RQ2.  

Prequisites outlines tools required to run the study. However, post-processed data from Github Copilot and LeetCode can be found in [output/copilot](output/copilot) and [output/leetcode](output/leetcode) respectively.  


Prequisites 
------------
- Leetcode account (all Leetcode related was done through this account: [MSR2022](https://leetcode.com/MSR2022/))
- SonarQube (refer to SonarQube's [installation guide](https://docs.sonarqube.org/latest/setup/get-started-2-minutes/)) 
- Python 3
- Access to Github Copilot (at this time, github copilot is still under technical preview, you can join the waitlist [here](https://github.com/features/copilot/signup))  

Structure 
------------
These are the structures of our repositories with descriptions to main folders and files:
- [src/](src/) contains all python scripts used for Step 1 and 3
    * [copy_paste.py](src/copy_paste.py): create 4 different files in Python, Java, JavaScript, and C for one LeetCode's question when providing the question contexts (function name, parameters, input, output, and comment) 
    * [get_stat.py](src/get_stat.py): analyze and summarize LeetCode's dump json files in [leetcode](output/leetcode) by statuses (Accepted, Runtime Error, Compile Error, Wrong Answer, Time Limit Exceeded)
- [output/](ouput/) contains all post-processed data to answer RQ1-RQ2
    * [copilot](output/copilot): contains 33 files named after 33 LeetCode's questions containing the top suggestion extracted from Github Copilot and the related question contexts (function name, parameters, input, output, and comment)  
    * [leetcode](output/leetcode): contains 7 dump json files containing information of all submissions to LeetCode (question title, url, status, etc)
    * [questions_data](output/questions_data): contains 2 csv files used to compose Table 1 and Figure 3
    * [sonar_java](output/sonar_java): a Maven project containing same 33 Java files in [copilot/java](output/copilot/java) for quick analysis with SonarQube   

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
