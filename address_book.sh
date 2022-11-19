create(){
    echo "enter address book name"
    read ab

    res='ls | grep $ab | wc -w'
    if [$res -gt 0]
    then
        echo "error: adress book already exist"
    else
        touch $ab
        echo "address book created"
    fi
}

display(){
    echo "enter address book name"
    read ab

    res='ls | grep $ab | wc -w'
    if [$res -gt 0]
    then
        cat $ab
    else
        echo "error: book is not present"
    fi
}

insert(){
    echo "enter address book name"
    read ab

    res='ls | grep $ab | wc -w'
    if [$res -gt 0]
    then 
        echo "enter email"
        read email

        len=`cat $ab | grep $email | wc -w`
        if [$len -gt 0]
        then 
            echo "error: email already exist!"
        else
            echo "enter first name,last name ,phone number"
            read fname lname mobile

            record=`echo $fname $lname $email $mobile`
            echo $record >> $ab
            echo "record inserted!"

        fi
    else
        echo "file not existing!"
    fi
}

modify(){
    echo "enter address book name"
    read ab

    res=`ls | grep $ab |wc -w`

    if[res -gt 0]
    then
        echo "enter email"
        read email

        len=`cat $ab | grep $email | wc -w`
            if[len -gt 0]
            then
                echo "enter data to modify fname,lname,mobileno."
                read fname lname mobile
                new =`echo $fname $lname $email $mobile`
                old = `cat $ab | grep $email`

                echo "old record: $old"
                echo "new record: $new"

                sed -i s/"$old"/"$new"/g $ab
                echo "record modified"

            
            else 
                echo "error: email is not present!"
            fi
    else
        echo "error :file is not existing!"
    fi

            
}

delete(){
    echo "enter address book"
    read ab

    res= `ls | grep $ab | wc -w`

    if[$res -gt 0]
    then
        echo "enter email id"
        read email

        len=`cat $ab | grep $email | wc -w`
        if[$len -gt 0]
        then 
            old=`cat $ab |grep $email`
            sed -i s/"$old"//g $ab
            echo "record deleted!"
        else
            echo "error : email not existing"
        fi
    else
        echo "error: file not exist"
    fi
}

while[true]:
do
    echo *****meu******
    echo "1.create"
    echo "2.display"
    echo "3.insert"
    echo "4.modify"
    echo "5.delete"
    
    echo "7.exit"
    echo "enter choice"

    read choice

    case $choice in:
        1) create;;
        2) display;;
        3) insert;;
        4) modify;;
        5) delete;;
        7) exit;;
        *) echo "invalid choice"
    esac

done