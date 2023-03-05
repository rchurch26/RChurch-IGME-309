#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Rahmel Church Jr. - rac3090@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	for (uint i = 0; i < m_uMeshCount; i++)
	{
		m_pMesh = new MyMesh();
		meshes.push_back(m_pMesh);
		meshes[i]->GenerateCube(1.0f, C_BLACK);
	}
		
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	//Create Top Antennas
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f, 3.75f, 0.0f)));
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(3.0f, 3.75f, 0.0f)));
	//Create Bottom Antennas
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-2.0f, 2.75f, 0.0f)));
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(2.0f, 2.75f, 0.0f)));
	//Top of Head
	for (uint i = 0; i < borderCount; i++)
	{
		meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f + i, 1.75f, 0.0f)));
	}
	//Second Row of Head
	for (uint i = 0; i < secondRowBorderCount; i++)
	{
		meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-4.0f + i, 0.75f, 0.0f)));
	}
	for (uint i = 0; i < secondRowMidCount; i++)
	{
		meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-1.0f + i, 0.75f, 0.0f)));
	}
	for (uint i = 0; i < secondRowBorderCount; i++)
	{
		meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(3.0f + i, 0.75f, 0.0f)));
	}
	//Third Row of Head
	for (uint i = 0; i < thirdRowCount; i++)
	{
		meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-5.0f + i, -0.25f, 0.0f)));
	}
	//Fourth Row of Head
	m_pMesh->Render(m4Projection, m4View, glm::translate(vector3(-5.0f, -1.25f, 0.0f)));
	for (uint i = 0; i < borderCount; i++)
	{
		meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f + i, -1.25f, 0.0f)));
	}
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(5.0f, -1.25f, 0.0f)));
	//Fifth Row of Head
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-5.0f, -2.25f, 0.0f)));
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f, -2.25f, 0.0f)));
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(3.0f, -2.25f, 0.0f)));
	meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(5.0f, -2.25f, 0.0f)));
	//Mouth of Head
	for (uint i = 0; i < mouthBorderCount; i++)
	{
		meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(-2.0f + i, -3.25f, 0.0f)));
	}
	for (uint i = 0; i < mouthBorderCount; i++)
	{
		meshes[0]->Render(m4Projection, m4View, glm::translate(vector3(1.0f + i, -3.25f, 0.0f)));
	}

	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//Release meshes
	for (uint i = 0; i < meshes.size(); i++)
	{
		delete meshes[i];
		meshes[i] == nullptr;
	}

	//release GUI
	ShutdownGUI();
}