class ActivitySelection:
    def __init__(self,start,finish):
        self.start = start
        self.finish = finish
    def __repr__(self) -> str:
        return f'{self.start}-{self.finish}'

my_activity = [ActivitySelection(1,4), ActivitySelection(3,5), ActivitySelection(0,6), ActivitySelection(5,7), ActivitySelection(3,9),ActivitySelection(5,9),ActivitySelection(6,10), ActivitySelection(8,11),ActivitySelection(8,12), ActivitySelection(2,14), ActivitySelection(12, 16)]
selected_activity = []
def activity_selection_problem(ind):

    m = ind + 1
    while m < len(my_activity) and my_activity[ind].finish >= my_activity[m].start :
        m += 1

    if m <= len(my_activity): 
        selected_activity.append(my_activity[ind])
        activity_selection_problem(m)
    


activity_selection_problem(0)
print(selected_activity)






