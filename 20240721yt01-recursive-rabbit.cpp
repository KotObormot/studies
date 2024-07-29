//https://www.youtube.com/watch?v=YUle4PBVS4c&t=890s
//  https://drive.google.com/drive/folders/1wLFlvgpcwOeGn1_Si2HutHUp7PUVRo8b
#include <iostream>

void rabbit_jumping(int& waysNumber, int nextPosition, int targetPosition, int maxJumpLength = 3) {
	/*std::cout << "Jump length = " << maxJumpLength << "\n";*/
	 	
	if(nextPosition > targetPosition) {
		return;
	} 
	
	if(nextPosition == targetPosition) {
		waysNumber++;
	}

	for(int jumpsLength = 1; jumpsLength <= maxJumpLength; jumpsLength++) {
		rabbit_jumping(waysNumber, nextPosition + jumpsLength, targetPosition, maxJumpLength);
	}
}

int main() {
	int n, k, numberOfAttempts = 0; 
	
	do {
	    std::cout << "Which step does the bunny want to jump to? (> 0) --> ";
	    std::cin >> n;
    }
	while(n <= 0);
	
	std::cout << "The default bunny hop length is 3. Would you like to enter a different value? (> 0) --> ";
	std::cin >> k;
	
	if(k > 0) {
        rabbit_jumping( numberOfAttempts, 0, n, k );
    } else {
	    rabbit_jumping(numberOfAttempts, 0, n );		
	}
	 

	std::cout << "Let's calculate...\n=================\n";
	std::cout << "The rabbit will be able to jump in " << numberOfAttempts << " attempts.\n";
	
}

