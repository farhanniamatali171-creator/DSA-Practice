#include <iostream>
#include <string>

struct Job{
    int id;
    std::string student;
    std::string document;
    int pages;
};

class PrintSpooler{
  private:
     Job jobs[6];
     int front,rear,count;

   int getIndex(int position){
      return (front+position)%6;
    }

  int findJob(int id){
     for(int i=0;i<count;i++){
         if(jobs[getIndex(i)].id == id)
         return i;
       }
      return -1;
   }

   void displayJob(Job j){
        std::cout<<"\nJob ID: "<< j.id << "\nStudent: "<< j.student
        << "\nDocument: " << j.document << "\nPages: "<< j.pages << "\n";
    }

public:
    PrintSpooler() {
        front=0;
        rear=-1;
        count=0;
    }

  void submitJob(Job j){
     if(j.id<=0 || j.student.find_first_not_of(" \t\n")==std::string::npos ||
        j.document.find_first_not_of(" \t\n")==std::string::npos ||j.pages<1||j.pages>100){
         std::cout<<"Invalid job details!\n";
         return;
        }

     if(findJob(j.id)!=-1){
          std::cout<<"Duplicate Job ID!\n";
          return;
        }
      if(count==6){
          std::cout<<"Spooler is full!\n";
          return;
        }
        rear=(rear+1)%6;
        jobs[rear]=j;
        count++;
        std::cout<<"Job submitted successfully!\n";
    }

    void printNext(){
        if (count==0){
            std::cout<<"No jobs waiting!\n";
            return;
        }
        std::cout<<"\nPrinting job:";
        displayJob(jobs[front]);
        front=(front+1)%6;
        count--;

      if(count==0){
         front=0;
         rear=-1;
      }
   }

    void cancelJob(int id){
       int position = findJob(id);
       if (position == -1){
          std::cout << "Job not found!\n";
        return;
        }
      for(int i=position; i<count-1;i++) {
          jobs[getIndex(i)]=jobs[getIndex(i+1)];
        }
        rear = (rear-1 +6)%6;
        count--;
      if(count==0){
         front=0;
         rear=-1;
        }
        std::cout<<"Job cancelled successfully!\n";
    }

    void searchJob(int id){
        int position = findJob(id);
        if (position==-1){
          std::cout<<"Job not found!\n";
          return;
       }
     displayJob(jobs[getIndex(position)]);
    }

   void displayAll(){
        if (count==0) {
           std::cout<<"No jobs waiting!\n";
           return;
      }
    std::cout<<"\nPending Jobs (FIFO Order):\n";
      for (int i = 0; i < count; i++) {
        displayJob(jobs[getIndex(i)]);
      }
    }
};

int main(){


    PrintSpooler spooler;
    Job j;
    // Submit six initial jobs
    Job initialJobs[6]={
        {601, "Ayesha Khan","print_report.pdf",12},
        {602, "Bilal Ahmed","assignment.cpp",5},
        {603, "Hina Malik","lecture_slides.pptx",20},
        {604, "Omar Shah","lab_manual.pdf",8},
        {605, "Zain Ali","notes.pdf",3},
        {606, "Maryam Noor", "project_report.pdf",30}};
    for (int i=0; i<6; i++){
    spooler.submitJob(initialJobs[i]);
    }

    //Print first two jobs
     spooler.printNext();
     spooler.printNext();

    //Reuse circular queue positions
    spooler.submitJob({607, "Ali Raza", "poster_design.pdf", 15});
    spooler.submitJob({608, "Sara Iqbal", "thesis_draft.pdf", 40});
    spooler.submitJob({609, "Test Student", "test.pdf", 10});

    //Cancel job 605
    spooler.cancelJob(605);

    //Search job 607
    spooler.searchJob(607);

    //Display all pending jobs
    spooler.displayAll();

    //Print remaining jobs
     while(true){
       spooler.printNext();
       break;
     }
    spooler.printNext();


    return 0;
}
