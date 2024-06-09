#pragma once

#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>

#include "Book.h"
#include "Resurs.h"
#include "Article.h"
#include "Dissertation.h"
#include "TSpisok.h"

namespace KursovV3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			textBox1->MouseMove += gcnew MouseEventHandler(this, &MyForm::textBox1_MouseMove);
			textBox2->MouseMove += gcnew MouseEventHandler(this, &MyForm::textBox1_MouseMove);
			// Привязка обработчика события к событию Click кнопки
			button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			button2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		}
		int k = 1;
		int word;
		bool enter = true;
		bool newLine = false;
		System::String^ file;
		TSpisok spisok;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;
		  

	protected:

	protected:

	protected:
	private: System::Windows::Forms::ToolTip^ toolTip2;

	private:
	private: System::Windows::Forms::ToolTip^ toolTip1;
		   /// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;	   

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(202, 223);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(111, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Malgun Gothic Semilight", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(13, 334);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(304, 19);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Здесь будут отображаться ваши ошибки";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(193, 249);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 37);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Имя файла";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(12, 354);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(388, 95);
			this->textBox2->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(406, 354);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 95);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Исправить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->FormBorderStyle = ::System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->ClientSize = System::Drawing::Size(506, 461);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void MyForm::textBox1_MouseMove(Object^ sender, MouseEventArgs^ e)
	{
		toolTip1->SetToolTip(this->textBox1, "Введите файл формата .txt (формат указывать не надо)");
		toolTip2->SetToolTip(this->textBox2, "Поле для исправления ошибок");
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		file = textBox2->Text;
		enter = true;
		button2->Enabled = false;
		textBox2->ReadOnly = true;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		button1->Enabled = false;
		textBox1->ReadOnly = true;

		int error;
		int lineW = 0;

		System::String^ filename = textBox1->Text;
		System::String^ file_1 = file;
		std::string line, line1;
		std::string fileName = msclr::interop::marshal_as<std::string>(filename);
		fileName += ".txt";

		std::ifstream input(fileName, std::ios::binary | std::ios::in);

		if (!input.is_open())
		{
			button1->Enabled = true;
			textBox1->ReadOnly = false;
			label1->Text = "Файл не найден";

			return;
		}

		std::regex urlPattern_1(R"(http)");
		std::regex urlPattern_2(R"(URL)");
		std::regex urlPattern_3(R"(Режим доступа)");
		std::regex urlPattern_4(R"(Электронный ресурс)");
		std::regex urlPattern_5(R"(//)");
		std::regex urlPattern_6(R"(дис.)");
		std::regex urlPattern_7(R"(утв.)");
		std::regex urlPattern_8(R"(защищена)");
		std::regex urlPattern_9(R"(утверждена)");

		while (!input.eof() && enter)
		{
			while (getline(input, line))
			{
				lineW++;

				System::String^ l = gcnew System::String(line.c_str());

				if (newLine)
				{
					if (lineW == word)
					{
						std::string file_2 = msclr::interop::marshal_as<std::string>(file_1);
						line = file_2;
						newLine = false;
					}
					else break;
				}

				if (std::regex_search(line, urlPattern_1) || std::regex_search(line, urlPattern_2) || std::regex_search(line, urlPattern_3) || std::regex_search(line, urlPattern_4))
				{
					// если электронный ресурс
					Resurs resurs(line);
					resurs.authors(); // распределяем авторов
					resurs.zaglInformation(); // распределение сведений
						
					error = resurs.errors();
					switch (error)
					{
					case 1:
					{
						label1->Text = "Ошибка: цифра в первом упоминании автора";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}

					case 2:
					{
						label1->Text = "Ошибка: цифра в сведениях об ответственности";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}

					case 3:
					{
						label1->Text = "Ошибка: цифра в дополнительных сведених об ответственности";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}
					}
					if (error < 4 && error > 0) break;

					error = resurs.cityes(); // чтение города
					switch (error)
					{
						case 1:
						{
							label1->Text = "Ошибка: цифра в виде ресурса";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 2:
						{
							label1->Text = "Ошибка: отсутствует вид ресурса";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 3:
						{
							label1->Text = "Ошибка: цифра в названии города";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 4:
						{
							label1->Text = "Ошибка: цифра в названии издательства";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 5:
						{
							label1->Text = "Ошибка: буква в году";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 6:
						{
							label1->Text = "Ошибка: отсутствует ссылка";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 7:
						{
							label1->Text = "Ошибка: отсутствует режим доступа";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						
					}
					if (error < 8 && error > 0) break;

					resurs.symbol();

					line = resurs.addLine(); // заполнение строки

					spisok.addSpisok(line);
				}
				else if (std::regex_search(line, urlPattern_5))
				{
					// если статья
					Article article(line);
					article.authors(); // распределяем авторов
					article.zaglInformation(); // распределение сведений
					article.zaglInformationArticle(); // распределение сведений

					error = article.errors();
					switch (error)
					{
					case 1:
					{
						label1->Text = "Ошибка: цифра в первом авторе";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}
					case 2:
					{
						label1->Text = "Ошибка: цифра в авторах";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}
					case 3:
					{
						label1->Text = "Ошибка: цифра в сведениях об ответственности";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}
					case 4:
					{
						label1->Text = "Ошибка: цифра в сведениях об ответственности книги";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}
					case 5:
					{
						label1->Text = "Ошибка: цифра в дополнительных сведениях об ответственности книги";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}

					}
					if (error < 6 && error > 0) break;

					error = article.cityes(); // чтение города
					switch (error)
					{
						case 1:
						{
							label1->Text = "Ошибка: цифра в названии города, либо отсутствие города";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 2:
						{
							label1->Text = "Ошибка: цифра в названии издательства";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 3:
						{
							label1->Text = "Ошибка: буква при написании года";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 4:
						{
							label1->Text = "Ошибка: буква при написании страницы";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						
					}
					if (error < 5 && error > 0) break;

					article.symbol();

					line = article.addLine(); // расстановка знаков

					spisok.addSpisok(line);
				}
				else if (std::regex_search(line, urlPattern_6) || std::regex_search(line, urlPattern_7) || std::regex_search(line, urlPattern_8) || std::regex_search(line, urlPattern_9))
				{
					// если диссертация
					Dissertation dis(line);
					dis.authors();

					error = dis.zaglInformation();
					switch (error)
					{
						case 1:
						{
							label1->Text = "Ошибка: буква в шифре номенклатуры";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						case 2:
						{
							label1->Text = "Ошибка: буква в дате защиты";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						case 3:
						{
							label1->Text = "Ошибка: буква в дате утверждения";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 4:
						{
							label1->Text = "Ошибка: цифра в сведениях об ответственности";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						
					}
					if (error < 5 && error > 0) break;

					error = dis.errors();
					switch (error)
					{
					case 1:
					{
						label1->Text = "Ошибка: цифра в первом упоминании автора";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}

					case 2:
					{
						label1->Text = "Ошибка: цифра в сведениях об ответственности";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}

					case 3:
					{
						label1->Text = "Ошибка: цифра в дополнительных сведених об ответственности";

						enter = false;
						textBox2->ReadOnly = false;

						button2->Enabled = true;
						newLine = true;

						textBox2->Text = l;
						word = lineW;

						break;
					}

					

					}
					if (error < 4 && error > 0) break;

					error = dis.cityes();
					switch (error)
					{
						case 1:
						{
							label1->Text = "Ошибка: цифра в названии города, либо отсутствие города";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 2:
						{
							label1->Text = "Ошибка: буква при написании года";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 3:
						{
							label1->Text = "Ошибка: буква при написании страницы";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						
					}
					if (error < 4 && error > 0) break;

					dis.symbol();

					line = dis.addLine();

					spisok.addSpisok(line);
				}
				else
				{
					// если книга 
					Book book(line);
					book.authors(); // распределяем авторов
					book.zaglInformation(); // распределение сведений

					error = book.errors();
					switch (error)
					{
						case 1:
						{
							label1->Text = "Ошибка: цифра в первом упоминании автора";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						case 2:
						{
							label1->Text = "Ошибка: цифра в сведениях об ответственности";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						case 3:
						{
							label1->Text = "Ошибка: цифра в дополнительных сведених об ответственности";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}

						

					}
					if (error < 4 && error > 0) break;

					error = book.cityes(); // чтение города
					switch (error)
					{
						case 1:
						{
							label1->Text = "Ошибка: цифра в названии города, либо отсутствие города";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 2:
						{
							label1->Text = "Ошибка: цифра в названии издательства, либо отсутствие издательства";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 3:
						{
							label1->Text = "Ошибка: буква при написании года";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
						case 4:
						{
							label1->Text = "Ошибка: буква при написании страницы";

							enter = false;
							textBox2->ReadOnly = false;

							button2->Enabled = true;
							newLine = true;

							textBox2->Text = l;
							word = lineW;

							break;
						}
					}
					if (error < 5 && error > 0) break;

					book.symbol();

					line = book.addLine(); // расстановка знаков

					spisok.addSpisok(line);
				}
			}
		}
			
		if (input.eof() && enter)
		{
			System::String^ final_1;
			final_1 = spisok.ret2Spisok();
			std::string final = msclr::interop::marshal_as<std::string>(final_1);

			final = spisok.sortSpisok(final);

			label1->Text = "Данные обработаны и занесены в файл Spisok.rtf";
			textBox2->Text = "";
			std::ofstream output("Spisok.rtf");

			bool fBig = false;

			// --------------------------------------------- Запись в ворд RTF формата -----------------------------------------------//
			if (output.is_open())
			{
				output << "{\\rtf1\\ansi\\ansicpg65001\\deff0\\nouicompat\\deflang1049{\\fonttbl{\\f0\\fnil\\fswiss Times New Roman;}}\\n";
				output << "\\viewkind4\\uc1\\pard\\cf1\\f0\\fs28 " << k << ") ";

				for (int i = 0; i < final.size(); i++)
				{
					if (final[i] == '\n' && i != final.size() - 1)
					{
						k++;
						output << "\\viewkind4\\uc1\\pard\\cf1\\f0\\fs28\\par\\n";
						output << "\\viewkind4\\uc1\\pard\\cf1\\f0\\fs28 " << k << ") ";
						fBig = false;
					}
					else 
					{
						if (final[i] == '$')
						{
							fBig = true;
							i++;
						}

						if (!fBig)
							output << "\\viewkind4\\uc1\\pard\\b1\\cf1\\f0\\fs28 " << final[i];
						else
							output << "\\viewkind4\\uc1\\pard\\b0\\cf1\\f0\\fs28 " << final[i];
					}
					output << "\\cf0\\f1\\fs17\\n";
				}
				output << "}\\n";

				output.close();
			}
			// -----------------------------------------------------------------------------------------------------------------------//
		}

		input.close();
	}	
};
}