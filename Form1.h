#pragma once

namespace ArmstrongProgram3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  ReportButton;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  HeadingTextbox;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->ReportButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->HeadingTextbox = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Location = System::Drawing::Point(16, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(617, 232);
			this->panel1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->ReportButton);
			this->groupBox2->Location = System::Drawing::Point(350, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(251, 229);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(25, 122);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 55);
			this->button2->TabIndex = 1;
			this->button2->Text = L"E&xit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::ExitButton_Click);
			// 
			// ReportButton
			// 
			this->ReportButton->Location = System::Drawing::Point(25, 19);
			this->ReportButton->Name = L"ReportButton";
			this->ReportButton->Size = System::Drawing::Size(105, 55);
			this->ReportButton->TabIndex = 0;
			this->ReportButton->Text = L"&Report";
			this->ReportButton->UseVisualStyleBackColor = true;
			this->ReportButton->Click += gcnew System::EventHandler(this, &Form1::ReportButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->HeadingTextbox);
			this->groupBox1->Location = System::Drawing::Point(20, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(305, 229);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// HeadingTextbox
			// 
			this->HeadingTextbox->Location = System::Drawing::Point(92, 174);
			this->HeadingTextbox->Name = L"HeadingTextbox";
			this->HeadingTextbox->Size = System::Drawing::Size(171, 20);
			this->HeadingTextbox->TabIndex = 0;
			this->HeadingTextbox->Click += gcnew System::EventHandler(this, &Form1::HeadingTextbox_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(660, 270);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panel1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ExitButtion(System::Object^  sender, System::EventArgs^  e) {
				  
			 }
private: System::Void Ex(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void HeadingTextbox_Click(System::Object^  sender, System::EventArgs^  e) {
			 HeadingTextbox->Clear();

		 }
private: System::Void ReportButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 InventoryItem * CurrentRecordPointer;
			 ifstream fin;
			 
			 int InitInventoryNumber = 0;
			 int InitManufacturerID = 0;
			 double InitPrice = 0;
			 double InitMarkup = 0.0;
			 char InitItemType[35] = "\0";
			 int  InitQuantity = 0;
			 double InitRetailPrice = 0.0;
			 char* ReportName;

			 //fin.open((char*)(void*)Marshal::StringToHGlobalAnsi(String::Concat(Directory::GetCurrentDirectory(),"\\ItemFileForInput.txt")));
			 
			 fin.open((char*) (void*)Marshal::StringToHGlobalAnsi 
				 (String::Concat(Directory::GetCurrentDirectory(),
				 "\\ItemFileForInput.txt")));


			if(!fin)
			 {
				 Application::Exit();
				 return;
			 } 

			 fin >> InitInventoryNumber;
			 fin >> InitManufacturerID;
			 fin >> InitPrice;
			 fin >> InitMarkup;
			 fin.ignore();
			 fin.get( InitItemType,31 );
			 fin >> InitQuantity;
			 while(fin)
			 {
				 CurrentRecordPointer = new InventoryItem;

				 CurrentRecordPointer->InsertItem( InitInventoryNumber,InitManufacturerID, InitPrice,  InitMarkup,   InitItemType, InitQuantity,  CurrentRecordPointer );
				 fin >> InitInventoryNumber;
				 fin >> InitManufacturerID;
				 fin >> InitPrice;
				 fin >> InitMarkup;
				 fin.ignore();
				 fin.get( InitItemType, 35 );
				 fin >> InitQuantity;
			 }

			 ReportName = (char*)(void*)Marshal::StringToHGlobalAnsi(HeadingTextbox->Text);

			 FirstRecordPointer->ListRecords(ReportName);

			 HeadingTextbox->Clear();
			 HeadingTextbox->Text = "Output File Created";

			delete CurrentRecordPointer;
			FirstRecordPointer = NULL;
			fin.close();
			
		 }
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
};
}

