def job_scheduling(jobs):
    jobs.sort(key = lambda x:x[2],reverse = True)
    md = max(job[1] for job in jobs)
    slots = [False]*(md+1)
    profit = 0
    jobs_names = []
    for job in jobs:
        name,d,p = job
        for i in range(d,0,-1):
            if not slots[i]:
                slots[i] = True
                jobs_names.append(name)
                profit = profit+p
                break
    print(profit)
    print(jobs_names)

names = ['A','B','C','D','E']
deadlines = [2,1,2,1,3]
profit = [100,19,27,25,15]
jobs = list(zip(names,deadlines,profit))
job_scheduling(jobs)