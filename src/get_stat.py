import json
import os

def main():
    # open all json files in the directory
    directory = 'output/leetcode/'
    files = [directory + f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

    # get all the submissions
    submissions = []
    for f in files:
        with open(f) as json_file:
            data = json.load(json_file)
            submissions_list = data['submissions_dump']
            for submission in submissions_list:
                submissions.append(submission)

    # get all submission with the same lang and title
    python_submissions = {}
    java_submissions = {}
    javascript_submissions = {}
    c_submissions = {}
    for submission in submissions:
        if submission['lang'] == 'python' and submission['title'] not in python_submissions:
                python_submissions[submission['title']] = submission
        elif submission['lang'] == 'java' and submission['title'] not in java_submissions: 
                java_submissions[submission['title']] = submission
        elif submission['lang'] == 'javascript' and submission['title'] not in javascript_submissions:
                javascript_submissions[submission['title']] = submission
        elif submission['lang'] == 'c' and submission['title'] not in c_submissions:
                c_submissions[submission['title']] = submission

    # group all python submissions by status_display
    python_status_display = {}
    for submission in python_submissions.values():
        if submission["status_display"] not in python_status_display:
            python_status_display[submission["status_display"]] = []
            python_status_display[submission["status_display"]].append(submission["title_slug"])
        else:
            python_status_display[submission["status_display"]].append(submission["title_slug"])
    
    # group all java submissions by status_display
    java_status_display = {}
    for submission in java_submissions.values():
        if submission["status_display"] not in java_status_display:
            java_status_display[submission["status_display"]] = []
            java_status_display[submission["status_display"]].append(submission["title_slug"])
        else:
            java_status_display[submission["status_display"]].append(submission["title_slug"])
    
    # group all javascript submissions by status_display
    javascript_status_display = {}
    for submission in javascript_submissions.values():
        if submission["status_display"] not in javascript_status_display:
            javascript_status_display[submission["status_display"]] = []
            javascript_status_display[submission["status_display"]].append(submission["title_slug"])
        else:
            javascript_status_display[submission["status_display"]].append(submission["title_slug"])

    # group all c submissions by status_display
    c_status_display = {}
    for submission in c_submissions.values():
        if submission["status_display"] not in c_status_display:
            c_status_display[submission["status_display"]] = []
            c_status_display[submission["status_display"]].append(submission["title_slug"])
        else:
            c_status_display[submission["status_display"]].append(submission["title_slug"])

    print("STATS")
    print("Python:")
    for key, value in python_status_display.items():
        print(key + ": " + str(len(value)))
    print("=========")
    print("Java:")
    for key, value in java_status_display.items():
        print(key + ": " + str(len(value)))
    print("=========")
    print("Javascript:")
    for key, value in javascript_status_display.items():
        print(key + ": " + str(len(value)))
    print("=========")
    print("C:")
    for key, value in c_status_display.items():
        print(key + ": " + str(len(value)))
    print("=========")    
main()
